// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME analysisdict
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "ROOT/RConfig.hxx"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Header files passed as explicit arguments
#include "MyAnalysis.h"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void *new_MyAnalysis(void *p = nullptr);
   static void *newArray_MyAnalysis(Long_t size, void *p);
   static void delete_MyAnalysis(void *p);
   static void deleteArray_MyAnalysis(void *p);
   static void destruct_MyAnalysis(void *p);
   static void streamer_MyAnalysis(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MyAnalysis*)
   {
      ::MyAnalysis *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::MyAnalysis >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("MyAnalysis", ::MyAnalysis::Class_Version(), "MyAnalysis.h", 22,
                  typeid(::MyAnalysis), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::MyAnalysis::Dictionary, isa_proxy, 16,
                  sizeof(::MyAnalysis) );
      instance.SetNew(&new_MyAnalysis);
      instance.SetNewArray(&newArray_MyAnalysis);
      instance.SetDelete(&delete_MyAnalysis);
      instance.SetDeleteArray(&deleteArray_MyAnalysis);
      instance.SetDestructor(&destruct_MyAnalysis);
      instance.SetStreamerFunc(&streamer_MyAnalysis);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MyAnalysis*)
   {
      return GenerateInitInstanceLocal(static_cast<::MyAnalysis*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::MyAnalysis*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr MyAnalysis::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *MyAnalysis::Class_Name()
{
   return "MyAnalysis";
}

//______________________________________________________________________________
const char *MyAnalysis::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyAnalysis*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int MyAnalysis::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyAnalysis*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *MyAnalysis::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyAnalysis*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *MyAnalysis::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyAnalysis*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void MyAnalysis::Streamer(TBuffer &R__b)
{
   // Stream an object of class MyAnalysis.

   TSelector::Streamer(R__b);
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_MyAnalysis(void *p) {
      return  p ? new(p) ::MyAnalysis : new ::MyAnalysis;
   }
   static void *newArray_MyAnalysis(Long_t nElements, void *p) {
      return p ? new(p) ::MyAnalysis[nElements] : new ::MyAnalysis[nElements];
   }
   // Wrapper around operator delete
   static void delete_MyAnalysis(void *p) {
      delete (static_cast<::MyAnalysis*>(p));
   }
   static void deleteArray_MyAnalysis(void *p) {
      delete [] (static_cast<::MyAnalysis*>(p));
   }
   static void destruct_MyAnalysis(void *p) {
      typedef ::MyAnalysis current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_MyAnalysis(TBuffer &buf, void *obj) {
      ((::MyAnalysis*)obj)->::MyAnalysis::Streamer(buf);
   }
} // end of namespace ROOT for class ::MyAnalysis

namespace {
  void TriggerDictionaryInitialization_analysisdict_Impl() {
    static const char* headers[] = {
"MyAnalysis.h",
nullptr
    };
    static const char* includePaths[] = {
"/home/ad/home/n/nele/Desktop/HEP/Exercises/Ex11/returned_answers/leonardo",
"/home/ad/lxhome/n/nele/Linux/root_v6.34.04/include/",
"/home/ad/home/n/nele/Desktop/HEP/Exercises/Ex11/returned_answers/leonardo/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "analysisdict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
class __attribute__((annotate("$clingAutoload$MyAnalysis.h")))  MyAnalysis;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "analysisdict dictionary payload"

#ifndef STANDALONE
  #define STANDALONE 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "MyAnalysis.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"MyAnalysis", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("analysisdict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_analysisdict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_analysisdict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_analysisdict() {
  TriggerDictionaryInitialization_analysisdict_Impl();
}
