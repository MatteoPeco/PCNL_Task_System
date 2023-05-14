#ifndef LWR_CONTROLLERS__VISIBILITY_CONTROL_H_
#define LWR_CONTROLLERS__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define LWR_CONTROLLERS_EXPORT __attribute__ ((dllexport))
    #define LWR_CONTROLLERS_IMPORT __attribute__ ((dllimport))
  #else
    #define LWR_CONTROLLERS_EXPORT __declspec(dllexport)
    #define LWR_CONTROLLERS_IMPORT __declspec(dllimport)
  #endif
  #ifdef LWR_CONTROLLERS_BUILDING_LIBRARY
    #define LWR_CONTROLLERS_PUBLIC LWR_CONTROLLERS_EXPORT
  #else
    #define LWR_CONTROLLERS_PUBLIC LWR_CONTROLLERS_IMPORT
  #endif
  #define LWR_CONTROLLERS_PUBLIC_TYPE LWR_CONTROLLERS_PUBLIC
  #define LWR_CONTROLLERS_LOCAL
#else
  #define LWR_CONTROLLERS_EXPORT __attribute__ ((visibility("default")))
  #define LWR_CONTROLLERS_IMPORT
  #if __GNUC__ >= 4
    #define LWR_CONTROLLERS_PUBLIC __attribute__ ((visibility("default")))
    #define LWR_CONTROLLERS_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define LWR_CONTROLLERS_PUBLIC
    #define LWR_CONTROLLERS_LOCAL
  #endif
  #define LWR_CONTROLLERS_PUBLIC_TYPE
#endif
#endif  // LWR_CONTROLLERS__VISIBILITY_CONTROL_H_
// Generated 02-May-2022 17:53:47
// Copyright 2019-2020 The MathWorks, Inc.
