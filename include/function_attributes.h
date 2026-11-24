#ifndef __FUNCTION_ATTRIBUTES_H_INCLUDED__
#define __FUNCTION_ATTRIBUTES_H_INCLUDED__

#ifdef __linux__

#define __attr_alias__(__target__) __attribute__((weak, alias(__target__)))
#define __attr_always_inline__ __attribute__((always_inline))
#ifdef __GNUC__
#define __attr_cdecl__
#else
#define __attr_cdecl__ __attribute__((cdecl))
#endif // __GNUC__
#define __attr_const__ __attribute__((const))
#define __attr_deprecated__ __attribute__((__deprecated__))
#define __attr_dllimport__ __attribute__((dllimport))
#define __attr_dllexport__ __attribute__((dllexport))
#define __attr_export__ __attribute__((visibility("default")))
#define __attr_fastcall__ __attribute__((fastcall))
#define __attr_format__(__archetype__, __string_index__, __first_to_check__) \
	__attribute__((                                                      \
		format(__archetype__, __string_index__, __first_to_check__)))
#define __attr_hidden__ __attribute__((visibility("hidden")))
#define __attr_leaf__ __attribute__((leaf))
#define __attr_malloc__ __attribute__((malloc))
#define __attr_naked__ __attribute__((naked))
#define __attr_noalias__
#define __attr_noinline__ __attribute__((noinline))
#define __attr_nonnull__ __attribute__((nonnull))
#define __attr_nonnull_arg__(...) __attribute__((nonnull(__VA_ARGS__)))
#define __attr_noreturn__ __attribute__((noreturn))
#define __attr_nothrow__ __attribute__((nothrow))
#define __attr_packed__(__decl__) __decl__ __attribute__((packed))
#define __attr_pure__ __attribute__((pure))
#define __attr_stdcall__ __attribute__((stdcall))
#define __attr_thiscall__ __attribute__((thiscall))
#define __attr_weak__ __attribute__((weak))

#elif defined _WIN32

#ifdef _MSC_VER

#define __attr_alias__(__target__)
#define __attr_always_inline__
#define __attr_cdecl__ __cdecl
#define __attr_const__
#define __attr_deprecated__ __declspec(deprecated)
#define __attr_dllimport__ __declspec(dllimport)
#define __attr_dllexport__ __declspec(dllexport)
#define __attr_export__ __declspec(dllexport)
#define __attr_fastcall__ __fastcall
#define __attr_format__(__archetype__, __string_index__, __first_to_check__)
#define __attr_hidden__
#define __attr_leaf__
#define __attr_malloc__
#define __attr_naked__ __declspec(naked)
#define __attr_noalias__ __declspec(noalias)
#define __attr_noinline__ __declspec(noinline)
#define __attr_nonnull__
#define __attr_nonnull_arg__(...)
#define __attr_noreturn__ __declspec(noreturn)
#define __attr_nothrow__ __declspec(nothrow)
#define __attr_packed__(__decl__) \
	__pragma(pack(push, 1)) __decl__ __pragma(pack(pop))
#define __attr_pure__
#define __attr_stdcall__ __stdcall
#define __attr_thiscall__ __thiscall
#define __attr_weak__

#elif defined __MINGW32__ || defined __MINGW64__

#define __attr_alias__(__target__)
#define __attr_always_inline__
#define __attr_cdecl__
#define __attr_const__ __MINGW_ATTRIB_CONST
#define __attr_deprecated__ __MINGW_ATTRIB_DEPRECATED
#define __attr_dllimport__
#define __attr_dllexport__
#define __attr_export__
#define __attr_fastcall__
#define __attr_format__(__archetype__, __string_index__, __first_to_check__)
#define __attr_hidden__
#define __attr_leaf__
#define __attr_malloc__ __MINGW_ATTRIB_MALLOC
#define __attr_naked__
#define __attr_noalias__
#define __attr_noinline__
#define __attr_nonnull__
#define __attr_nonnull_arg__(...) \
	__MINGW_ATTRIB_NONNULL(__argindex__, __VA_ARGS__)
#define __attr_noreturn__ __MINGW_ATTRIB_NORETURN
#define __attr_nothrow__ __MINGW_NOTHROW
#define __attr_packed__(__decl__)
#define __attr_pure__ __MINGW_ATTRIB_PURE
#define __attr_stdcall__
#define __attr_thiscall__
#define __attr_weak__

#elif defined __CYGWIN__

#define __attr_alias__(__target__)
#define __attr_always_inline__
#define __attr_cdecl__
#define __attr_const_
#define __attr_dllimport__
#define __attr_dllexport__
#define __attr_export__
#define __attr_fastcall__
#define __attr_format__(__archetype__, __string_index__, __first_to_check__)
#define __attr_hidden__
#define __attr_leaf__
#define __attr_malloc__
#define __attr_naked__
#define __attr_noalias__
#define __attr_noinline__
#define __attr_nonnull__
#define __attr_nonnull_arg__(...)
#define __attr_noreturn__
#define __attr_nothrow__
#define __attr_packed__(__decl__)
#define __attr_pure__
#define __attr_stdcall__
#define __attr_thiscall__
#define __attr_weak__

#else

#define __attr_alias__(__target__)
#define __attr_always_inline__
#define __attr_cdecl__
#define __attr_const_
#define __attr_dllimport__
#define __attr_dllexport__
#define __attr_export__
#define __attr_fastcall__
#define __attr_format__(__archetype__, __string_index__, __first_to_check__)
#define __attr_hidden__
#define __attr_leaf__
#define __attr_malloc__
#define __attr_naked__
#define __attr_noalias__
#define __attr_noinline__
#define __attr_nonnull__
#define __attr_nonnull_arg__(...)
#define __attr_noreturn__
#define __attr_nothrow__
#define __attr_packed__(__decl__)
#define __attr_pure__
#define __attr_stdcall__
#define __attr_thiscall__
#define __attr_weak__

#endif // _MSC_VER

#else

#define __attr_alias__(__target__)
#define __attr_always_inline__
#define __attr_cdecl__
#define __attr_const_
#define __attr_dllimport__
#define __attr_dllexport__
#define __attr_export__
#define __attr_fastcall__
#define __attr_format__(__archetype__, __string_index__, __first_to_check__)
#define __attr_hidden__
#define __attr_leaf__
#define __attr_malloc__
#define __attr_naked__
#define __attr_noalias__
#define __attr_noinline__
#define __attr_nonnull__
#define __attr_nonnull_arg__(...)
#define __attr_noreturn__
#define __attr_nothrow__
#define __attr_packed__(__decl__)
#define __attr_pure__
#define __attr_stdcall__
#define __attr_thiscall__
#define __attr_weak__

#endif // __linux__

#endif // __FUNCTION_ATTRIBUTES_H_INCLUDED__
