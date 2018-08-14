/*
 * Copyright 2018 Google
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

/* Automatically generated nanopb constant definitions */
/* Generated by nanopb-0.3.9.1 at Tue Aug 14 12:19:56 2018. */

#include "document.nanopb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t google_firestore_v1beta1_Document_fields[5] = {
    PB_FIELD(  1, STRING  , SINGULAR, CALLBACK, FIRST, google_firestore_v1beta1_Document, name, name, 0),
    PB_FIELD(  2, MESSAGE , REPEATED, CALLBACK, OTHER, google_firestore_v1beta1_Document, fields, name, &google_firestore_v1beta1_Document_FieldsEntry_fields),
    PB_FIELD(  3, MESSAGE , SINGULAR, STATIC  , OTHER, google_firestore_v1beta1_Document, create_time, fields, &google_protobuf_Timestamp_fields),
    PB_FIELD(  4, MESSAGE , SINGULAR, STATIC  , OTHER, google_firestore_v1beta1_Document, update_time, create_time, &google_protobuf_Timestamp_fields),
    PB_LAST_FIELD
};

const pb_field_t google_firestore_v1beta1_Document_FieldsEntry_fields[3] = {
    PB_FIELD(  1, STRING  , SINGULAR, CALLBACK, FIRST, google_firestore_v1beta1_Document_FieldsEntry, key, key, 0),
    PB_FIELD(  2, MESSAGE , SINGULAR, STATIC  , OTHER, google_firestore_v1beta1_Document_FieldsEntry, value, key, &google_firestore_v1beta1_Value_fields),
    PB_LAST_FIELD
};

const pb_field_t google_firestore_v1beta1_Value_fields[12] = {
    PB_FIELD(  1, BOOL    , SINGULAR, STATIC  , FIRST, google_firestore_v1beta1_Value, boolean_value, boolean_value, 0),
    PB_FIELD(  2, INT64   , SINGULAR, STATIC  , OTHER, google_firestore_v1beta1_Value, integer_value, boolean_value, 0),
    PB_FIELD(  3, DOUBLE  , SINGULAR, STATIC  , OTHER, google_firestore_v1beta1_Value, double_value, integer_value, 0),
    PB_FIELD(  5, STRING  , SINGULAR, CALLBACK, OTHER, google_firestore_v1beta1_Value, reference_value, double_value, 0),
    PB_FIELD(  6, MESSAGE , SINGULAR, STATIC  , OTHER, google_firestore_v1beta1_Value, map_value, reference_value, &google_firestore_v1beta1_MapValue_fields),
    PB_FIELD(  8, MESSAGE , SINGULAR, STATIC  , OTHER, google_firestore_v1beta1_Value, geo_point_value, map_value, &google_type_LatLng_fields),
    PB_FIELD(  9, MESSAGE , SINGULAR, STATIC  , OTHER, google_firestore_v1beta1_Value, array_value, geo_point_value, &google_firestore_v1beta1_ArrayValue_fields),
    PB_FIELD( 10, MESSAGE , SINGULAR, STATIC  , OTHER, google_firestore_v1beta1_Value, timestamp_value, array_value, &google_protobuf_Timestamp_fields),
    PB_FIELD( 11, UENUM   , SINGULAR, STATIC  , OTHER, google_firestore_v1beta1_Value, null_value, timestamp_value, 0),
    PB_FIELD( 17, STRING  , SINGULAR, CALLBACK, OTHER, google_firestore_v1beta1_Value, string_value, null_value, 0),
    PB_FIELD( 18, BYTES   , SINGULAR, CALLBACK, OTHER, google_firestore_v1beta1_Value, bytes_value, string_value, 0),
    PB_LAST_FIELD
};

const pb_field_t google_firestore_v1beta1_ArrayValue_fields[2] = {
    PB_FIELD(  1, MESSAGE , REPEATED, CALLBACK, FIRST, google_firestore_v1beta1_ArrayValue, values, values, &google_firestore_v1beta1_Value_fields),
    PB_LAST_FIELD
};

const pb_field_t google_firestore_v1beta1_MapValue_fields[2] = {
    PB_FIELD(  1, MESSAGE , REPEATED, CALLBACK, FIRST, google_firestore_v1beta1_MapValue, fields, fields, &google_firestore_v1beta1_MapValue_FieldsEntry_fields),
    PB_LAST_FIELD
};

const pb_field_t google_firestore_v1beta1_MapValue_FieldsEntry_fields[3] = {
    PB_FIELD(  1, STRING  , SINGULAR, CALLBACK, FIRST, google_firestore_v1beta1_MapValue_FieldsEntry, key, key, 0),
    PB_FIELD(  2, MESSAGE , SINGULAR, STATIC  , OTHER, google_firestore_v1beta1_MapValue_FieldsEntry, value, key, &google_firestore_v1beta1_Value_fields),
    PB_LAST_FIELD
};


/* Check that field information fits in pb_field_t */
#if !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_32BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in 8 or 16 bit
 * field descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(google_firestore_v1beta1_Document, create_time) < 65536 && pb_membersize(google_firestore_v1beta1_Document, update_time) < 65536 && pb_membersize(google_firestore_v1beta1_Document_FieldsEntry, value) < 65536 && pb_membersize(google_firestore_v1beta1_Value, timestamp_value) < 65536 && pb_membersize(google_firestore_v1beta1_Value, geo_point_value) < 65536 && pb_membersize(google_firestore_v1beta1_Value, array_value) < 65536 && pb_membersize(google_firestore_v1beta1_Value, map_value) < 65536 && pb_membersize(google_firestore_v1beta1_MapValue_FieldsEntry, value) < 65536), YOU_MUST_DEFINE_PB_FIELD_32BIT_FOR_MESSAGES_google_firestore_v1beta1_Document_google_firestore_v1beta1_Document_FieldsEntry_google_firestore_v1beta1_Value_google_firestore_v1beta1_ArrayValue_google_firestore_v1beta1_MapValue_google_firestore_v1beta1_MapValue_FieldsEntry)
#endif

#if !defined(PB_FIELD_16BIT) && !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_16BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in the default
 * 8 bit descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(google_firestore_v1beta1_Document, create_time) < 256 && pb_membersize(google_firestore_v1beta1_Document, update_time) < 256 && pb_membersize(google_firestore_v1beta1_Document_FieldsEntry, value) < 256 && pb_membersize(google_firestore_v1beta1_Value, timestamp_value) < 256 && pb_membersize(google_firestore_v1beta1_Value, geo_point_value) < 256 && pb_membersize(google_firestore_v1beta1_Value, array_value) < 256 && pb_membersize(google_firestore_v1beta1_Value, map_value) < 256 && pb_membersize(google_firestore_v1beta1_MapValue_FieldsEntry, value) < 256), YOU_MUST_DEFINE_PB_FIELD_16BIT_FOR_MESSAGES_google_firestore_v1beta1_Document_google_firestore_v1beta1_Document_FieldsEntry_google_firestore_v1beta1_Value_google_firestore_v1beta1_ArrayValue_google_firestore_v1beta1_MapValue_google_firestore_v1beta1_MapValue_FieldsEntry)
#endif


/* On some platforms (such as AVR), double is really float.
 * These are not directly supported by nanopb, but see example_avr_double.
 * To get rid of this error, remove any double fields from your .proto.
 */
PB_STATIC_ASSERT(sizeof(double) == 8, DOUBLE_MUST_BE_8_BYTES)

/* @@protoc_insertion_point(eof) */