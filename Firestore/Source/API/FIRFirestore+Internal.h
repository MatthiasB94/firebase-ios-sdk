/*
 * Copyright 2017 Google
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import "FIRFirestore.h"
#import "FIRListenerRegistration.h"

#include <memory>
#include <string>

#include "Firestore/core/src/firebase/firestore/api/firestore.h"
#include "Firestore/core/src/firebase/firestore/auth/credentials_provider.h"
#include "Firestore/core/src/firebase/firestore/util/async_queue.h"

@class FIRApp;
@class FSTFirestoreClient;
@class FSTUserDataConverter;

namespace api = firebase::firestore::api;
namespace auth = firebase::firestore::auth;
namespace model = firebase::firestore::model;
namespace util = firebase::firestore::util;

NS_ASSUME_NONNULL_BEGIN

/** Provides a registry management interface for FIRFirestore instances. */
@protocol FSTFirestoreInstanceRegistry

/** Removes the FIRFirestore instance with given database name from registry. */
- (void)removeInstanceWithDatabase:(NSString *)database;

@end

@interface FIRFirestore (/* Init */)

/**
 * Initializes a Firestore object with all the required parameters directly. This exists so that
 * tests can create FIRFirestore objects without needing FIRApp.
 */
- (instancetype)initWithDatabaseID:(model::DatabaseId)databaseID
                    persistenceKey:(std::string)persistenceKey
               credentialsProvider:(std::shared_ptr<auth::CredentialsProvider>)credentialsProvider
                       workerQueue:(std::shared_ptr<util::AsyncQueue>)workerQueue
                       firebaseApp:(FIRApp *)app
                  instanceRegistry:(nullable id<FSTFirestoreInstanceRegistry>)registry;
@end

/** Internal FIRFirestore API we don't want exposed in our public header files. */
@interface FIRFirestore (Internal)

/** Checks to see if logging is is globally enabled for the Firestore client. */
+ (BOOL)isLoggingEnabled;

+ (FIRFirestore *)recoverFromFirestore:(std::shared_ptr<api::Firestore>)firestore;

- (void)terminateInternalWithCompletion:(nullable void (^)(NSError *_Nullable error))completion;

- (const std::shared_ptr<util::AsyncQueue> &)workerQueue;

/**
 * Attaches a listener for a snapshots-in-sync event. Server-generated
 * updates and local changes can affect multiple snapshot listeners.
 * The snapshots-in-sync event indicates that all listeners affected by
 * a given change have fired.
 *
 * NOTE: The snapshots-in-sync event only indicates that listeners are
 * in sync with each other, but does not relate to whether those
 * snapshots are in sync with the server. Use SnapshotMetadata in the
 * individual listeners to determine if a snapshot is from the cache or
 * the server.
 *
 * @param listener A callback to be called every time all snapshot
 * listeners are in sync with each other.
 * @return A FIRListenerRegistration object that can be used to remove the
 * listener.
 */
- (id<FIRListenerRegistration>)addSnapshotsInSyncListener:(void (^)(void))listener
    NS_SWIFT_NAME(addSnapshotsInSyncListener(_:));

@property(nonatomic, assign, readonly) std::shared_ptr<api::Firestore> wrapped;

@property(nonatomic, assign, readonly) const model::DatabaseId &databaseID;
@property(nonatomic, strong, readonly) FSTUserDataConverter *dataConverter;

@end

NS_ASSUME_NONNULL_END
