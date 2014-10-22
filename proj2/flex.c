char copyright[] =
"@(#) Copyright (c) 1990 The Regents of the University of California.\n All rights reserved.\n";

typedef long unsigned int size_t;
typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;
typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;
typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;
typedef long int __quad_t;
typedef unsigned long int __u_quad_t;
typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
typedef struct { int __val[2]; } __fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;
typedef int __daddr_t;
typedef long int __swblk_t;
typedef int __key_t;
typedef int __clockid_t;
typedef void * __timer_t;
typedef long int __blksize_t;
typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;
typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;
typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;
typedef long int __ssize_t;
typedef __off64_t __loff_t;
typedef __quad_t *__qaddr_t;
typedef char *__caddr_t;
typedef long int __intptr_t;
typedef unsigned int __socklen_t;

typedef struct _IO_FILE FILE;







typedef struct _IO_FILE __FILE;
typedef int wchar_t;
typedef unsigned int wint_t;
typedef struct
{
  int __count;
  union
  {
    wint_t __wch;
    char __wchb[4];
  } __value;
} __mbstate_t;
typedef struct
{
  __off_t __pos;
  __mbstate_t __state;
} _G_fpos_t;
typedef struct
{
  __off64_t __pos;
  __mbstate_t __state;
} _G_fpos64_t;
enum
{
  __GCONV_OK = 0,
  __GCONV_NOCONV,
  __GCONV_NODB,
  __GCONV_NOMEM,
  __GCONV_EMPTY_INPUT,
  __GCONV_FULL_OUTPUT,
  __GCONV_ILLEGAL_INPUT,
  __GCONV_INCOMPLETE_INPUT,
  __GCONV_ILLEGAL_DESCRIPTOR,
  __GCONV_INTERNAL_ERROR
};
enum
{
  __GCONV_IS_LAST = 0x0001,
  __GCONV_IGNORE_ERRORS = 0x0002
};
struct __gconv_step;
struct __gconv_step_data;
struct __gconv_loaded_object;
struct __gconv_trans_data;
typedef int (*__gconv_fct) (struct __gconv_step *, struct __gconv_step_data *,
       __const unsigned char **, __const unsigned char *,
       unsigned char **, size_t *, int, int);
typedef wint_t (*__gconv_btowc_fct) (struct __gconv_step *, unsigned char);
typedef int (*__gconv_init_fct) (struct __gconv_step *);
typedef void (*__gconv_end_fct) (struct __gconv_step *);
typedef int (*__gconv_trans_fct) (struct __gconv_step *,
      struct __gconv_step_data *, void *,
      __const unsigned char *,
      __const unsigned char **,
      __const unsigned char *, unsigned char **,
      size_t *);
typedef int (*__gconv_trans_context_fct) (void *, __const unsigned char *,
       __const unsigned char *,
       unsigned char *, unsigned char *);
typedef int (*__gconv_trans_query_fct) (__const char *, __const char ***,
     size_t *);
typedef int (*__gconv_trans_init_fct) (void **, const char *);
typedef void (*__gconv_trans_end_fct) (void *);
struct __gconv_trans_data
{
  __gconv_trans_fct __trans_fct;
  __gconv_trans_context_fct __trans_context_fct;
  __gconv_trans_end_fct __trans_end_fct;
  void *__data;
  struct __gconv_trans_data *__next;
};
struct __gconv_step
{
  struct __gconv_loaded_object *__shlib_handle;
  __const char *__modname;
  int __counter;
  char *__from_name;
  char *__to_name;
  __gconv_fct __fct;
  __gconv_btowc_fct __btowc_fct;
  __gconv_init_fct __init_fct;
  __gconv_end_fct __end_fct;
  int __min_needed_from;
  int __max_needed_from;
  int __min_needed_to;
  int __max_needed_to;
  int __stateful;
  void *__data;
};
struct __gconv_step_data
{
  unsigned char *__outbuf;
  unsigned char *__outbufend;
  int __flags;
  int __invocation_counter;



  int __internal_use;

  __mbstate_t *__statep;
  __mbstate_t __state;



  struct __gconv_trans_data *__trans;
};



typedef struct __gconv_info
{
  size_t __nsteps;
  struct __gconv_step *__steps;
  __extension__ struct __gconv_step_data __data [];
} *__gconv_t;
typedef union
{
  struct __gconv_info __cd;
  struct
  {
    struct __gconv_info __cd;
    struct __gconv_step_data __data;
  } __combined;
} _G_iconv_t;
typedef int _G_int16_t __attribute__ ((__mode__ (__HI__)));
typedef int _G_int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int _G_uint16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int _G_uint32_t __attribute__ ((__mode__ (__SI__)));
typedef __builtin_va_list __gnuc_va_list;
struct _IO_jump_t; struct _IO_FILE;
typedef void _IO_lock_t;
struct _IO_marker {
  struct _IO_marker *_next;
  struct _IO_FILE *_sbuf;
  int _pos;


};


enum __codecvt_result
{
  __codecvt_ok,
  __codecvt_partial,
  __codecvt_error,
  __codecvt_noconv
};
struct _IO_FILE {
  int _flags;
  char* _IO_read_ptr;
  char* _IO_read_end;
  char* _IO_read_base;
  char* _IO_write_base;
  char* _IO_write_ptr;
  char* _IO_write_end;
  char* _IO_buf_base;
  char* _IO_buf_end;
  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;
  struct _IO_marker *_markers;
  struct _IO_FILE *_chain;
  int _fileno;
  int _flags2;
  __off_t _old_offset;
  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];
  _IO_lock_t *_lock;
  __off64_t _offset;
  void *__pad1;
  void *__pad2;
  void *__pad3;
  void *__pad4;
  size_t __pad5;
  int _mode;
  char _unused2[15 * sizeof (int) - 4 * sizeof (void *) - sizeof (size_t)];
};
typedef struct _IO_FILE _IO_FILE;
struct _IO_FILE_plus;
extern struct _IO_FILE_plus _IO_2_1_stdin_;
extern struct _IO_FILE_plus _IO_2_1_stdout_;
extern struct _IO_FILE_plus _IO_2_1_stderr_;
typedef __ssize_t __io_read_fn (void *__cookie, char *__buf, size_t __nbytes);
typedef __ssize_t __io_write_fn (void *__cookie, __const char *__buf,
     size_t __n);
typedef int __io_seek_fn (void *__cookie, __off64_t *__pos, int __w);
typedef int __io_close_fn (void *__cookie);
extern int __underflow (_IO_FILE *);
extern int __uflow (_IO_FILE *);
extern int __overflow (_IO_FILE *, int);
extern wint_t __wunderflow (_IO_FILE *);
extern wint_t __wuflow (_IO_FILE *);
extern wint_t __woverflow (_IO_FILE *, wint_t);
extern int _IO_getc (_IO_FILE *__fp);
extern int _IO_putc (int __c, _IO_FILE *__fp);
extern int _IO_feof (_IO_FILE *__fp) __attribute__ ((__nothrow__));
extern int _IO_ferror (_IO_FILE *__fp) __attribute__ ((__nothrow__));
extern int _IO_peekc_locked (_IO_FILE *__fp);
extern void _IO_flockfile (_IO_FILE *) __attribute__ ((__nothrow__));
extern void _IO_funlockfile (_IO_FILE *) __attribute__ ((__nothrow__));
extern int _IO_ftrylockfile (_IO_FILE *) __attribute__ ((__nothrow__));
extern int _IO_vfscanf (_IO_FILE * __restrict, const char * __restrict,
   __gnuc_va_list, int *__restrict);
extern int _IO_vfprintf (_IO_FILE *__restrict, const char *__restrict,
    __gnuc_va_list);
extern __ssize_t _IO_padn (_IO_FILE *, int, __ssize_t);
extern size_t _IO_sgetn (_IO_FILE *, void *, size_t);
extern __off64_t _IO_seekoff (_IO_FILE *, __off64_t, int, int);
extern __off64_t _IO_seekpos (_IO_FILE *, __off64_t, int);
extern void _IO_free_backup_area (_IO_FILE *) __attribute__ ((__nothrow__));

typedef _G_fpos_t fpos_t;

extern struct _IO_FILE *stdin;
extern struct _IO_FILE *stdout;
extern struct _IO_FILE *stderr;

extern int remove (__const char *__filename) __attribute__ ((__nothrow__));
extern int rename (__const char *__old, __const char *__new) __attribute__ ((__nothrow__));


extern FILE *tmpfile (void);
extern char *tmpnam (char *__s) __attribute__ ((__nothrow__));

extern char *tmpnam_r (char *__s) __attribute__ ((__nothrow__));
extern char *tempnam (__const char *__dir, __const char *__pfx)
     __attribute__ ((__nothrow__)) __attribute__ ((__malloc__));

extern int fclose (FILE *__stream);
extern int fflush (FILE *__stream);

extern int fflush_unlocked (FILE *__stream);

extern FILE *fopen (__const char *__restrict __filename,
      __const char *__restrict __modes);
extern FILE *freopen (__const char *__restrict __filename,
        __const char *__restrict __modes,
        FILE *__restrict __stream);

extern FILE *fdopen (int __fd, __const char *__modes) __attribute__ ((__nothrow__));

extern void setbuf (FILE *__restrict __stream, char *__restrict __buf) __attribute__ ((__nothrow__));

extern int setvbuf (FILE *__restrict __stream, char *__restrict __buf,
      int __modes, size_t __n) __attribute__ ((__nothrow__));





extern void setbuffer (FILE *__restrict __stream, char *__restrict __buf,
         size_t __size) __attribute__ ((__nothrow__));


extern void setlinebuf (FILE *__stream) __attribute__ ((__nothrow__));








extern int fprintf (FILE *__restrict __stream,
      __const char *__restrict __format, ...);




extern int printf (__const char *__restrict __format, ...);

extern int sprintf (char *__restrict __s,
      __const char *__restrict __format, ...) __attribute__ ((__nothrow__));





extern int vfprintf (FILE *__restrict __s, __const char *__restrict __format,
       __gnuc_va_list __arg);




extern int vprintf (__const char *__restrict __format, __gnuc_va_list __arg);

extern int vsprintf (char *__restrict __s, __const char *__restrict __format,
       __gnuc_va_list __arg) __attribute__ ((__nothrow__));





extern int snprintf (char *__restrict __s, size_t __maxlen,
       __const char *__restrict __format, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 4)));

extern int vsnprintf (char *__restrict __s, size_t __maxlen,
        __const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 0)));


extern int fscanf (FILE *__restrict __stream,
     __const char *__restrict __format, ...) ;
extern int scanf (__const char *__restrict __format, ...) ;
extern int sscanf (__const char *__restrict __s,
     __const char *__restrict __format, ...) __attribute__ ((__nothrow__));


extern int fgetc (FILE *__stream);
extern int getc (FILE *__stream);
extern int getchar (void);

extern int getc_unlocked (FILE *__stream);
extern int getchar_unlocked (void);
extern int fgetc_unlocked (FILE *__stream);

extern int fputc (int __c, FILE *__stream);
extern int putc (int __c, FILE *__stream);
extern int putchar (int __c);

extern int fputc_unlocked (int __c, FILE *__stream);
extern int putc_unlocked (int __c, FILE *__stream);
extern int putchar_unlocked (int __c);
extern int getw (FILE *__stream);
extern int putw (int __w, FILE *__stream);

extern char *fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
     ;
extern char *gets (char *__s) ;


extern int fputs (__const char *__restrict __s, FILE *__restrict __stream);
extern int puts (__const char *__s);
extern int ungetc (int __c, FILE *__stream);
extern size_t fread (void *__restrict __ptr, size_t __size,
       size_t __n, FILE *__restrict __stream) ;
extern size_t fwrite (__const void *__restrict __ptr, size_t __size,
        size_t __n, FILE *__restrict __s) ;

extern size_t fread_unlocked (void *__restrict __ptr, size_t __size,
         size_t __n, FILE *__restrict __stream) ;
extern size_t fwrite_unlocked (__const void *__restrict __ptr, size_t __size,
          size_t __n, FILE *__restrict __stream) ;

extern int fseek (FILE *__stream, long int __off, int __whence);
extern long int ftell (FILE *__stream) ;
extern void rewind (FILE *__stream);

extern int fseeko (FILE *__stream, __off_t __off, int __whence);
extern __off_t ftello (FILE *__stream) ;

extern int fgetpos (FILE *__restrict __stream, fpos_t *__restrict __pos);
extern int fsetpos (FILE *__stream, __const fpos_t *__pos);


extern void clearerr (FILE *__stream) __attribute__ ((__nothrow__));
extern int feof (FILE *__stream) __attribute__ ((__nothrow__)) ;
extern int ferror (FILE *__stream) __attribute__ ((__nothrow__)) ;

extern void clearerr_unlocked (FILE *__stream) __attribute__ ((__nothrow__));
extern int feof_unlocked (FILE *__stream) __attribute__ ((__nothrow__)) ;
extern int ferror_unlocked (FILE *__stream) __attribute__ ((__nothrow__)) ;

extern void perror (__const char *__s);

extern int sys_nerr;
extern __const char *__const sys_errlist[];
extern int fileno (FILE *__stream) __attribute__ ((__nothrow__)) ;
extern int fileno_unlocked (FILE *__stream) __attribute__ ((__nothrow__)) ;
extern FILE *popen (__const char *__command, __const char *__modes) ;
extern int pclose (FILE *__stream);
extern char *ctermid (char *__s) __attribute__ ((__nothrow__));
extern void flockfile (FILE *__stream) __attribute__ ((__nothrow__));
extern int ftrylockfile (FILE *__stream) __attribute__ ((__nothrow__)) ;
extern void funlockfile (FILE *__stream) __attribute__ ((__nothrow__));


enum
{
  _ISupper = ((0) < 8 ? ((1 << (0)) << 8) : ((1 << (0)) >> 8)),
  _ISlower = ((1) < 8 ? ((1 << (1)) << 8) : ((1 << (1)) >> 8)),
  _ISalpha = ((2) < 8 ? ((1 << (2)) << 8) : ((1 << (2)) >> 8)),
  _ISdigit = ((3) < 8 ? ((1 << (3)) << 8) : ((1 << (3)) >> 8)),
  _ISxdigit = ((4) < 8 ? ((1 << (4)) << 8) : ((1 << (4)) >> 8)),
  _ISspace = ((5) < 8 ? ((1 << (5)) << 8) : ((1 << (5)) >> 8)),
  _ISprint = ((6) < 8 ? ((1 << (6)) << 8) : ((1 << (6)) >> 8)),
  _ISgraph = ((7) < 8 ? ((1 << (7)) << 8) : ((1 << (7)) >> 8)),
  _ISblank = ((8) < 8 ? ((1 << (8)) << 8) : ((1 << (8)) >> 8)),
  _IScntrl = ((9) < 8 ? ((1 << (9)) << 8) : ((1 << (9)) >> 8)),
  _ISpunct = ((10) < 8 ? ((1 << (10)) << 8) : ((1 << (10)) >> 8)),
  _ISalnum = ((11) < 8 ? ((1 << (11)) << 8) : ((1 << (11)) >> 8))
};
extern __const unsigned short int **__ctype_b_loc (void)
     __attribute__ ((__const));
extern __const __int32_t **__ctype_tolower_loc (void)
     __attribute__ ((__const));
extern __const __int32_t **__ctype_toupper_loc (void)
     __attribute__ ((__const));

extern int isalnum (int) __attribute__ ((__nothrow__));
extern int isalpha (int) __attribute__ ((__nothrow__));
extern int iscntrl (int) __attribute__ ((__nothrow__));
extern int isdigit (int) __attribute__ ((__nothrow__));
extern int islower (int) __attribute__ ((__nothrow__));
extern int isgraph (int) __attribute__ ((__nothrow__));
extern int isprint (int) __attribute__ ((__nothrow__));
extern int ispunct (int) __attribute__ ((__nothrow__));
extern int isspace (int) __attribute__ ((__nothrow__));
extern int isupper (int) __attribute__ ((__nothrow__));
extern int isxdigit (int) __attribute__ ((__nothrow__));
extern int tolower (int __c) __attribute__ ((__nothrow__));
extern int toupper (int __c) __attribute__ ((__nothrow__));

extern int isascii (int __c) __attribute__ ((__nothrow__));
extern int toascii (int __c) __attribute__ ((__nothrow__));
extern int _toupper (int) __attribute__ ((__nothrow__));
extern int _tolower (int) __attribute__ ((__nothrow__));


extern int bcmp (__const void *__s1, __const void *__s2, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__));
extern void bcopy (__const void *__src, void *__dest, size_t __n) __attribute__ ((__nothrow__));
extern void bzero (void *__s, size_t __n) __attribute__ ((__nothrow__));
extern int ffs (int __i) __attribute__ ((__nothrow__)) __attribute__ ((const));
extern char *index (__const char *__s, int __c) __attribute__ ((__nothrow__)) __attribute__ ((__pure__));
extern char *rindex (__const char *__s, int __c) __attribute__ ((__nothrow__)) __attribute__ ((__pure__));
extern int strcasecmp (__const char *__s1, __const char *__s2)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__));
extern int strncasecmp (__const char *__s1, __const char *__s2, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__));



typedef struct
  {
    int quot;
    int rem;
  } div_t;
typedef struct
  {
    long int quot;
    long int rem;
  } ldiv_t;

extern size_t __ctype_get_mb_cur_max (void) __attribute__ ((__nothrow__)) ;

extern double atof (__const char *__nptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;
extern int atoi (__const char *__nptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;
extern long int atol (__const char *__nptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;


__extension__ extern long long int atoll (__const char *__nptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;


extern double strtod (__const char *__restrict __nptr,
        char **__restrict __endptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;


extern long int strtol (__const char *__restrict __nptr,
   char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
extern unsigned long int strtoul (__const char *__restrict __nptr,
      char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;

__extension__
extern long long int strtoq (__const char *__restrict __nptr,
        char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
__extension__
extern unsigned long long int strtouq (__const char *__restrict __nptr,
           char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;

__extension__
extern long long int strtoll (__const char *__restrict __nptr,
         char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
__extension__
extern unsigned long long int strtoull (__const char *__restrict __nptr,
     char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;

extern double __strtod_internal (__const char *__restrict __nptr,
     char **__restrict __endptr, int __group)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
extern float __strtof_internal (__const char *__restrict __nptr,
    char **__restrict __endptr, int __group)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
extern long double __strtold_internal (__const char *__restrict __nptr,
           char **__restrict __endptr,
           int __group)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
extern long int __strtol_internal (__const char *__restrict __nptr,
       char **__restrict __endptr,
       int __base, int __group)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
extern unsigned long int __strtoul_internal (__const char *__restrict __nptr,
          char **__restrict __endptr,
          int __base, int __group)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
__extension__
extern long long int __strtoll_internal (__const char *__restrict __nptr,
      char **__restrict __endptr,
      int __base, int __group)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
__extension__
extern unsigned long long int __strtoull_internal (__const char *
         __restrict __nptr,
         char **__restrict __endptr,
         int __base, int __group)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
extern char *l64a (long int __n) __attribute__ ((__nothrow__)) ;
extern long int a64l (__const char *__s)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;

typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;
typedef __loff_t loff_t;
typedef __ino_t ino_t;
typedef __dev_t dev_t;
typedef __gid_t gid_t;
typedef __mode_t mode_t;
typedef __nlink_t nlink_t;
typedef __uid_t uid_t;
typedef __off_t off_t;
typedef __pid_t pid_t;
typedef __id_t id_t;
typedef __ssize_t ssize_t;
typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;
typedef __key_t key_t;

typedef __time_t time_t;


typedef __clockid_t clockid_t;
typedef __timer_t timer_t;
typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;
typedef int int8_t __attribute__ ((__mode__ (__QI__)));
typedef int int16_t __attribute__ ((__mode__ (__HI__)));
typedef int int32_t __attribute__ ((__mode__ (__SI__)));
typedef int int64_t __attribute__ ((__mode__ (__DI__)));
typedef unsigned int u_int8_t __attribute__ ((__mode__ (__QI__)));
typedef unsigned int u_int16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int u_int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int u_int64_t __attribute__ ((__mode__ (__DI__)));
typedef int register_t __attribute__ ((__mode__ (__word__)));
typedef int __sig_atomic_t;
typedef struct
  {
    unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
  } __sigset_t;
typedef __sigset_t sigset_t;
struct timespec
  {
    __time_t tv_sec;
    long int tv_nsec;
  };
struct timeval
  {
    __time_t tv_sec;
    __suseconds_t tv_usec;
  };
typedef __suseconds_t suseconds_t;
typedef long int __fd_mask;
typedef struct
  {
    __fd_mask __fds_bits[1024 / (8 * sizeof (__fd_mask))];
  } fd_set;
typedef __fd_mask fd_mask;

extern int select (int __nfds, fd_set *__restrict __readfds,
     fd_set *__restrict __writefds,
     fd_set *__restrict __exceptfds,
     struct timeval *__restrict __timeout);
extern int pselect (int __nfds, fd_set *__restrict __readfds,
      fd_set *__restrict __writefds,
      fd_set *__restrict __exceptfds,
      const struct timespec *__restrict __timeout,
      const __sigset_t *__restrict __sigmask);

__extension__
extern __inline unsigned int gnu_dev_major (unsigned long long int __dev)
     __attribute__ ((__nothrow__));
__extension__
extern __inline unsigned int gnu_dev_minor (unsigned long long int __dev)
     __attribute__ ((__nothrow__));
__extension__
extern __inline unsigned long long int gnu_dev_makedev (unsigned int __major,
       unsigned int __minor)
     __attribute__ ((__nothrow__));
__extension__ extern __inline unsigned int
__attribute__ ((__nothrow__)) gnu_dev_major (unsigned long long int __dev)
{
  return ((__dev >> 8) & 0xfff) | ((unsigned int) (__dev >> 32) & ~0xfff);
}
__extension__ extern __inline unsigned int
__attribute__ ((__nothrow__)) gnu_dev_minor (unsigned long long int __dev)
{
  return (__dev & 0xff) | ((unsigned int) (__dev >> 12) & ~0xff);
}
__extension__ extern __inline unsigned long long int
__attribute__ ((__nothrow__)) gnu_dev_makedev (unsigned int __major, unsigned int __minor)
{
  return ((__minor & 0xff) | ((__major & 0xfff) << 8)
   | (((unsigned long long int) (__minor & ~0xff)) << 12)
   | (((unsigned long long int) (__major & ~0xfff)) << 32));
}
typedef __blkcnt_t blkcnt_t;
typedef __fsblkcnt_t fsblkcnt_t;
typedef __fsfilcnt_t fsfilcnt_t;
typedef unsigned long int pthread_t;
typedef union
{
  char __size[56];
  long int __align;
} pthread_attr_t;
typedef struct __pthread_internal_list
{
  struct __pthread_internal_list *__prev;
  struct __pthread_internal_list *__next;
} __pthread_list_t;
typedef union
{
  struct __pthread_mutex_s
  {
    int __lock;
    unsigned int __count;
    int __owner;
    unsigned int __nusers;
    int __kind;
    int __spins;
    __pthread_list_t __list;
  } __data;
  char __size[40];
  long int __align;
} pthread_mutex_t;
typedef union
{
  char __size[4];
  int __align;
} pthread_mutexattr_t;
typedef union
{
  struct
  {
    int __lock;
    unsigned int __futex;
    __extension__ unsigned long long int __total_seq;
    __extension__ unsigned long long int __wakeup_seq;
    __extension__ unsigned long long int __woken_seq;
    void *__mutex;
    unsigned int __nwaiters;
    unsigned int __broadcast_seq;
  } __data;
  char __size[48];
  __extension__ long long int __align;
} pthread_cond_t;
typedef union
{
  char __size[4];
  int __align;
} pthread_condattr_t;
typedef unsigned int pthread_key_t;
typedef int pthread_once_t;
typedef union
{
  struct
  {
    int __lock;
    unsigned int __nr_readers;
    unsigned int __readers_wakeup;
    unsigned int __writer_wakeup;
    unsigned int __nr_readers_queued;
    unsigned int __nr_writers_queued;
    int __writer;
    int __shared;
    unsigned long int __pad1;
    unsigned long int __pad2;
    unsigned int __flags;
  } __data;
  char __size[56];
  long int __align;
} pthread_rwlock_t;
typedef union
{
  char __size[8];
  long int __align;
} pthread_rwlockattr_t;
typedef volatile int pthread_spinlock_t;
typedef union
{
  char __size[32];
  long int __align;
} pthread_barrier_t;
typedef union
{
  char __size[4];
  int __align;
} pthread_barrierattr_t;

extern long int random (void) __attribute__ ((__nothrow__));
extern void srandom (unsigned int __seed) __attribute__ ((__nothrow__));
extern char *initstate (unsigned int __seed, char *__statebuf,
   size_t __statelen) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));
extern char *setstate (char *__statebuf) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
struct random_data
  {
    int32_t *fptr;
    int32_t *rptr;
    int32_t *state;
    int rand_type;
    int rand_deg;
    int rand_sep;
    int32_t *end_ptr;
  };
extern int random_r (struct random_data *__restrict __buf,
       int32_t *__restrict __result) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int srandom_r (unsigned int __seed, struct random_data *__buf)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));
extern int initstate_r (unsigned int __seed, char *__restrict __statebuf,
   size_t __statelen,
   struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2, 4)));
extern int setstate_r (char *__restrict __statebuf,
         struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));

extern int rand (void) __attribute__ ((__nothrow__));
extern void srand (unsigned int __seed) __attribute__ ((__nothrow__));

extern int rand_r (unsigned int *__seed) __attribute__ ((__nothrow__));
extern double drand48 (void) __attribute__ ((__nothrow__));
extern double erand48 (unsigned short int __xsubi[3]) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern long int lrand48 (void) __attribute__ ((__nothrow__));
extern long int nrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern long int mrand48 (void) __attribute__ ((__nothrow__));
extern long int jrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern void srand48 (long int __seedval) __attribute__ ((__nothrow__));
extern unsigned short int *seed48 (unsigned short int __seed16v[3])
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern void lcong48 (unsigned short int __param[7]) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
struct drand48_data
  {
    unsigned short int __x[3];
    unsigned short int __old_x[3];
    unsigned short int __c;
    unsigned short int __init;
    unsigned long long int __a;
  };
extern int drand48_r (struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int erand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int lrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int nrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int mrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int jrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int srand48_r (long int __seedval, struct drand48_data *__buffer)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));
extern int seed48_r (unsigned short int __seed16v[3],
       struct drand48_data *__buffer) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int lcong48_r (unsigned short int __param[7],
        struct drand48_data *__buffer)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));

extern void *malloc (size_t __size) __attribute__ ((__nothrow__)) __attribute__ ((__malloc__)) ;
extern void *calloc (size_t __nmemb, size_t __size)
     __attribute__ ((__nothrow__)) __attribute__ ((__malloc__)) ;


extern void *realloc (void *__ptr, size_t __size)
     __attribute__ ((__nothrow__)) __attribute__ ((__malloc__)) __attribute__ ((__warn_unused_result__));
extern void free (void *__ptr) __attribute__ ((__nothrow__));

extern void cfree (void *__ptr) __attribute__ ((__nothrow__));

extern void *alloca (size_t __size) __attribute__ ((__nothrow__));

extern void *valloc (size_t __size) __attribute__ ((__nothrow__)) __attribute__ ((__malloc__)) ;
extern int posix_memalign (void **__memptr, size_t __alignment, size_t __size)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;

extern void abort (void) __attribute__ ((__nothrow__)) __attribute__ ((__noreturn__));
extern int atexit (void (*__func) (void)) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));

extern int on_exit (void (*__func) (int __status, void *__arg), void *__arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));

extern void exit (int __status) __attribute__ ((__nothrow__)) __attribute__ ((__noreturn__));


extern char *getenv (__const char *__name) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;

extern char *__secure_getenv (__const char *__name)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
extern int putenv (char *__string) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int setenv (__const char *__name, __const char *__value, int __replace)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));
extern int unsetenv (__const char *__name) __attribute__ ((__nothrow__));
extern int clearenv (void) __attribute__ ((__nothrow__));
extern char *mktemp (char *__template) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
extern int mkstemp (char *__template) __attribute__ ((__nonnull__ (1))) ;
extern char *mkdtemp (char *__template) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;

extern int system (__const char *__command) ;

extern char *realpath (__const char *__restrict __name,
         char *__restrict __resolved) __attribute__ ((__nothrow__)) ;
typedef int (*__compar_fn_t) (__const void *, __const void *);

extern void *bsearch (__const void *__key, __const void *__base,
        size_t __nmemb, size_t __size, __compar_fn_t __compar)
     __attribute__ ((__nonnull__ (1, 2, 5))) ;
extern void qsort (void *__base, size_t __nmemb, size_t __size,
     __compar_fn_t __compar) __attribute__ ((__nonnull__ (1, 4)));
extern int abs (int __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__)) ;
extern long int labs (long int __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__)) ;


extern div_t div (int __numer, int __denom)
     __attribute__ ((__nothrow__)) __attribute__ ((__const__)) ;
extern ldiv_t ldiv (long int __numer, long int __denom)
     __attribute__ ((__nothrow__)) __attribute__ ((__const__)) ;

extern char *ecvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *fcvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *gcvt (double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3))) ;
extern char *qecvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qfcvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qgcvt (long double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3))) ;
extern int ecvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int fcvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int qecvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int qfcvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4, 5)));

extern int mblen (__const char *__s, size_t __n) __attribute__ ((__nothrow__)) ;
extern int mbtowc (wchar_t *__restrict __pwc,
     __const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__)) ;
extern int wctomb (char *__s, wchar_t __wchar) __attribute__ ((__nothrow__)) ;
extern size_t mbstowcs (wchar_t *__restrict __pwcs,
   __const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__));
extern size_t wcstombs (char *__restrict __s,
   __const wchar_t *__restrict __pwcs, size_t __n)
     __attribute__ ((__nothrow__));

extern int rpmatch (__const char *__response) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
extern int posix_openpt (int __oflag) ;




extern int getloadavg (double __loadavg[], int __nelem)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));

struct hash_entry
 {
 struct hash_entry *prev, *next;
 char *name;
 char *str_val;
 int int_val;
 } ;
typedef struct hash_entry **hash_table;
extern struct hash_entry *ndtbl[101];
extern struct hash_entry *sctbl[101];
extern struct hash_entry *ccltab[101];
extern int printstats, syntaxerror, eofseen, ddebug, trace, nowarn, spprdflt;
extern int interactive, caseins, lex_compat, useecs, fulltbl, usemecs;
extern int fullspd, gen_line_dirs, performance_report, backing_up_report;
extern int C_plus_plus, long_align, use_read, yytext_is_array, csize;
extern int yymore_used, reject, real_reject, continued_action;
extern int yymore_really_used, reject_really_used;
extern int datapos, dataline, linenum;
extern FILE *skelfile, *yyin, *backing_up_file;
extern char *skel[];
extern int skel_ind;
extern char *infilename;
extern char **input_files;
extern int num_input_files;
extern char *program_name;
extern char *action_array;
extern int action_size;
extern int defs1_offset, prolog_offset, action_offset, action_index;
extern int onestate[500], onesym[500];
extern int onenext[500], onedef[500], onesp;
extern int current_mns, num_rules, num_eof_rules, default_rule;
extern int current_max_rules, lastnfa;
extern int *firstst, *lastst, *finalst, *transchar, *trans1, *trans2;
extern int *accptnum, *assoc_rule, *state_type;
extern int *rule_type, *rule_linenum, *rule_useful;
extern int current_state_type;
extern int variable_trailing_context_rules;
extern int numtemps, numprots, protprev[50], protnext[50], prottbl[50];
extern int protcomst[50], firstprot, lastprot, protsave[2000];
extern int numecs, nextecm[256 + 1], ecgroup[256 + 1], nummecs;
extern int tecfwd[256 + 1], tecbck[256 + 1];
extern int lastsc, current_max_scs, *scset, *scbol, *scxclu, *sceof, *actvsc;
extern char **scname;
extern int current_max_dfa_size, current_max_xpairs;
extern int current_max_template_xpairs, current_max_dfas;
extern int lastdfa, *nxt, *chk, *tnxt;
extern int *base, *def, *nultrans, NUL_ec, tblend, firstfree, **dss, *dfasiz;
extern union dfaacc_union
 {
 int *dfaacc_set;
 int dfaacc_state;
 } *dfaacc;
extern int *accsiz, *dhash, numas;
extern int numsnpairs, jambase, jamstate;
extern int end_of_buffer_state;
extern int lastccl, current_maxccls, *cclmap, *ccllen, *cclng, cclreuse;
extern int current_max_ccl_tbl_size;
extern unsigned char *ccltbl;
extern char nmstr[2048];
extern int sectnum, nummt, hshcol, dfaeql, numeps, eps2, num_reallocs;
extern int tmpuses, totnst, peakpairs, numuniq, numdup, hshsave;
extern int num_backing_up, bol_needed;
void *allocate_array (int, int);
void *reallocate_array (void*, int, int);
void *flex_alloc (unsigned int);
void *flex_realloc (void*, unsigned int);
void flex_free (void*);
extern int yylval;
extern void ccladd (int, int);
extern int cclinit (void);
extern void cclnegate (int);
extern void list_character_set (FILE*, int[]);
extern void increase_max_dfas (void);
extern void ntod (void);
extern void ccl2ecl (void);
extern int cre8ecs (int[], int[], int);
extern void mkeccl (unsigned char[], int, int[], int[], int, int);
extern void mkechar (int, int[], int[]);
extern void make_tables (void);
extern void flexend (int);
extern void usage (void);
extern void add_action ( char *new_text );
extern int all_lower (register char *);
extern int all_upper (register char *);
extern void bubble (int [], int);
extern void check_char (int c);
extern void cshell (unsigned char [], int, int);
extern void dataend (void);
extern void flexerror (char[]);
extern void flexfatal (char[]);
extern void lerrif (char[], int);
extern void lerrsf (char[], char[]);
extern void line_directive_out (FILE*);
extern void mark_defs1 (void);
extern void mark_prolog (void);
extern void mk2data (int);
extern void mkdata (int);
extern int myctoi (char []);
extern char *readable_form (int);
extern void skelout (void);
extern void transition_struct_out (int, int);
extern void *yy_flex_xmalloc ( int );
extern void zero_out (char *, int);
extern void add_accept (int, int);
extern int copysingl (int, int);
extern void dumpnfa (int);
extern void finish_rule (int, int, int, int);
extern int link_machines (int, int);
extern void mark_beginning_as_normal (register int);
extern int mkbranch (int, int);
extern int mkclos (int);
extern int mkopt (int);
extern int mkor (int, int);
extern int mkposcl (int);
extern int mkrep (int, int, int);
extern int mkstate (int);
extern void new_rule (void);
extern void format_pinpoint_message (char[], char[]);
extern void pinpoint_message (char[]);
void line_warning ( char[], int );
void line_pinpoint ( char[], int );
extern void format_synerr (char [], char[]);
extern void synerr (char []);
extern void warn (char []);
extern int yyparse (void);
extern int flexscan (void);
extern void set_input_file (char*);
extern int yywrap (void);
extern void cclinstal (unsigned char [], int);
extern int ccllookup (unsigned char []);
extern void ndinstal (char[], unsigned char[]);
extern void scextend (void);
extern void scinstal (char[], int);
extern int sclookup (char[]);
extern void bldtbl (int[], int, int, int, int);
extern void cmptmps (void);
extern void expand_nxt_chk (void);
extern void inittbl (void);
extern void mkdeftbl (void);
extern void mk1tbl (int, int, int, int);
extern void place_state (int*, int, int);
extern void stack1 (int, int, int, int);
extern int yylex (void);
extern int yylval;
static char flex_version[] = "2.4.7";
void flexinit (int, char**);
void readin (void);
void set_up_initial_allocations (void);
int printstats, syntaxerror, eofseen, ddebug, trace, nowarn, spprdflt;
int interactive, caseins, lex_compat, useecs, fulltbl, usemecs;
int fullspd, gen_line_dirs, performance_report, backing_up_report;
int C_plus_plus, long_align, use_read, yytext_is_array, csize;
int yymore_used, reject, real_reject, continued_action;
int yymore_really_used, reject_really_used;
int datapos, dataline, linenum;
FILE *skelfile = ((void *)0);
FILE *err = ((void *)0);
int skel_ind = 0;
char *action_array;
int action_size, defs1_offset, prolog_offset, action_offset, action_index;
char *infilename = ((void *)0);
int onestate[500], onesym[500];
int onenext[500], onedef[500], onesp;
int current_mns, num_rules, num_eof_rules, default_rule;
int current_max_rules, lastnfa;
int *firstst, *lastst, *finalst, *transchar, *trans1, *trans2;
int *accptnum, *assoc_rule, *state_type;
int *rule_type, *rule_linenum, *rule_useful;
int current_state_type;
int variable_trailing_context_rules;
int numtemps, numprots, protprev[50], protnext[50], prottbl[50];
int protcomst[50], firstprot, lastprot, protsave[2000];
int numecs, nextecm[256 + 1], ecgroup[256 + 1], nummecs, tecfwd[256 + 1];
int tecbck[256 + 1];
int lastsc, current_max_scs, *scset, *scbol, *scxclu, *sceof, *actvsc;
char **scname;
int current_max_dfa_size, current_max_xpairs;
int current_max_template_xpairs, current_max_dfas;
int lastdfa, *nxt, *chk, *tnxt;
int *base, *def, *nultrans, NUL_ec, tblend, firstfree, **dss, *dfasiz;
union dfaacc_union *dfaacc;
int *accsiz, *dhash, numas;
int numsnpairs, jambase, jamstate;
int lastccl, current_maxccls, *cclmap, *ccllen, *cclng, cclreuse;
int current_max_ccl_tbl_size;
unsigned char *ccltbl;
char nmstr[2048];
int sectnum, nummt, hshcol, dfaeql, numeps, eps2, num_reallocs;
int tmpuses, totnst, peakpairs, numuniq, numdup, hshsave;
int num_backing_up, bol_needed;
FILE *backing_up_file;
int end_of_buffer_state;
char **input_files;
int num_input_files;
char *program_name;
static char *outfile_template = "lex.%s.%s";
static char outfile_path[64];
static int outfile_created = 0;
static int use_stdout;
static char *skelname = ((void *)0);
static char *prefix = "yy";
int main( argc, argv )
int argc;
char **argv;
 {
 int i;
 if(--argc >0){
                err = fopen( *++argv, "w" );
                --argv; ++argc;
        }
 flexinit( argc, argv );
 readin();
 ntod();
 for ( i = 1; i <= num_rules; ++i )
  if ( ! rule_useful[i] && i != default_rule )
   line_warning( "rule cannot be matched",
     rule_linenum[i] );
 if ( spprdflt && ! reject && rule_useful[default_rule] )
  line_warning( "-s option given but default rule can be matched",
   rule_linenum[default_rule] );
 make_tables();
 flexend( 0 );
 return 0;
 }
void flexend( exit_status )
int exit_status;
 {
 int tblsiz;
 int unlink();
 if ( skelfile != ((void *)0) )
  {
  if ( ferror( skelfile ) )
   flexfatal(
    "error occurred when reading skeleton file" );
  else if ( fclose( skelfile ) )
   flexfatal(
    "error occurred when closing skeleton file" );
  }
 if ( exit_status != 0 && outfile_created )
  {
  if ( ferror( stdout ) )
   flexfatal( "error occurred when writing output file" );
  else if ( fclose( stdout ) )
   flexfatal( "error occurred when closing output file" );
  else if ( unlink( outfile_path ) )
   flexfatal( "error occurred when deleting output file" );
  }
 if ( backing_up_report && backing_up_file )
  {
  if ( num_backing_up == 0 )
   fprintf( backing_up_file, "No backing up.\n" );
  else if ( fullspd || fulltbl )
   fprintf( backing_up_file,
    "%d backing up (non-accepting) states.\n",
    num_backing_up );
  else
   fprintf( backing_up_file,
    "Compressed tables always back up.\n" );
  if ( ferror( backing_up_file ) )
   flexfatal( "error occurred when writing backup file" );
  else if ( fclose( backing_up_file ) )
   flexfatal( "error occurred when closing backup file" );
  }
 if ( printstats )
  {
  fprintf( err, "%s version %s usage statistics:\n",
   program_name, flex_version );
  fprintf( err, "  scanner options: -" );
  if ( C_plus_plus )
   _IO_putc ('+', err);
  if ( backing_up_report )
   _IO_putc ('b', err);
  if ( ddebug )
   _IO_putc ('d', err);
  if ( caseins )
   _IO_putc ('i', err);
  if ( lex_compat )
   _IO_putc ('l', err);
  if ( performance_report > 0 )
   _IO_putc ('p', err);
  if ( performance_report > 1 )
   _IO_putc ('p', err);
  if ( spprdflt )
   _IO_putc ('s', err);
  if ( use_stdout )
   _IO_putc ('t', err);
  if ( printstats )
   _IO_putc ('v', err);
  if ( nowarn )
   _IO_putc ('w', err);
  if ( ! interactive )
   _IO_putc ('B', err);
  if ( interactive )
   _IO_putc ('I', err);
  if ( ! gen_line_dirs )
   _IO_putc ('L', err);
  if ( trace )
   _IO_putc ('T', err);
  if ( csize == 128 )
   _IO_putc ('7', err);
  else
   _IO_putc ('8', err);
  fprintf( err, " -C" );
  if ( long_align )
   _IO_putc ('a', err);
  if ( fulltbl )
   _IO_putc ('f', err);
  if ( fullspd )
   _IO_putc ('F', err);
  if ( useecs )
   _IO_putc ('e', err);
  if ( usemecs )
   _IO_putc ('m', err);
  if ( use_read )
   _IO_putc ('r', err);
  if ( skelname )
   fprintf( err, " -S%s", skelname );
  if ( strcmp( prefix, "yy" ) )
   fprintf( err, " -P%s", prefix );
  _IO_putc ('\n', err);
  fprintf( err, "  %d/%d NFA states\n", lastnfa, current_mns );
  fprintf( err, "  %d/%d DFA states (%d words)\n", lastdfa,
   current_max_dfas, totnst );
  fprintf( err, "  %d rules\n",
  num_rules + num_eof_rules - 1 );
  if ( num_backing_up == 0 )
   fprintf( err, "  No backing up\n" );
  else if ( fullspd || fulltbl )
   fprintf( err,
    "  %d backing-up (non-accepting) states\n",
    num_backing_up );
  else
   fprintf( err,
    "  Compressed tables always back-up\n" );
  if ( bol_needed )
   fprintf( err,
    "  Beginning-of-line patterns used\n" );
  fprintf( err, "  %d/%d start conditions\n", lastsc,
   current_max_scs );
  fprintf( err,
   "  %d epsilon states, %d double epsilon states\n",
   numeps, eps2 );
  if ( lastccl == 0 )
   fprintf( err, "  no character classes\n" );
  else
   fprintf( err,
 "  %d/%d character classes needed %d/%d words of storage, %d reused\n",
    lastccl, current_maxccls,
    cclmap[lastccl] + ccllen[lastccl],
    current_max_ccl_tbl_size, cclreuse );
  fprintf( err, "  %d state/nextstate pairs created\n",
   numsnpairs );
  fprintf( err, "  %d/%d unique/duplicate transitions\n",
   numuniq, numdup );
  if ( fulltbl )
   {
   tblsiz = lastdfa * numecs;
   fprintf( err, "  %d table entries\n", tblsiz );
   }
  else
   {
   tblsiz = 2 * (lastdfa + numtemps) + 2 * tblend;
   fprintf( err, "  %d/%d base-def entries created\n",
    lastdfa + numtemps, current_max_dfas );
   fprintf( err,
    "  %d/%d (peak %d) nxt-chk entries created\n",
    tblend, current_max_xpairs, peakpairs );
   fprintf( err,
   "  %d/%d (peak %d) template nxt-chk entries created\n",
    numtemps * nummecs, current_max_template_xpairs,
    numtemps * numecs );
   fprintf( err, "  %d empty table entries\n", nummt );
   fprintf( err, "  %d protos created\n", numprots );
   fprintf( err, "  %d templates created, %d uses\n",
    numtemps, tmpuses );
   }
  if ( useecs )
   {
   tblsiz = tblsiz + csize;
   fprintf( err,
    "  %d/%d equivalence classes created\n",
    numecs, csize );
   }
  if ( usemecs )
   {
   tblsiz = tblsiz + numecs;
   fprintf( err,
    "  %d/%d meta-equivalence classes created\n",
    nummecs, csize );
   }
  fprintf( err,
   "  %d (%d saved) hash collisions, %d DFAs equal\n",
   hshcol, hshsave, dfaeql );
  fprintf( err, "  %d sets of reallocations needed\n",
   num_reallocs );
  fprintf( err, "  %d total table entries needed\n", tblsiz );
  }
 exit( exit_status );
 }
void flexinit( argc, argv )
int argc;
char **argv;
 {
 int i, sawcmpflag;
 int csize_given, interactive_given;
 char *arg, *mktemp();
 printstats = syntaxerror = trace = spprdflt = caseins = 0;
 lex_compat = 0;
 C_plus_plus = backing_up_report = ddebug = fulltbl = fullspd = 0;
 long_align = nowarn = yymore_used = continued_action = reject = 0;
 yytext_is_array = yymore_really_used = reject_really_used = 0;
 gen_line_dirs = usemecs = useecs = 1;
 performance_report = 0;
 sawcmpflag = 0;
 use_read = use_stdout = 0;
 csize_given = 0;
 interactive_given = 0;
 action_size = 2048;
 action_array = (char *) allocate_array( action_size, sizeof( char ) );
 defs1_offset = prolog_offset = action_offset = action_index = 0;
 action_array[0] = '\0';
        program_name = "Executable";
 if ( program_name[0] != '\0' &&
      program_name[strlen( program_name ) - 1] == '+' )
  C_plus_plus = 1;
        ++argv;--argc;
 for ( --argc, ++argv; argc ; --argc, ++argv )
  {
  if ( argv[0][0] != '-' || argv[0][1] == '\0' )
   break;
  arg = argv[0];
  for ( i = 1; arg[i] != '\0'; ++i )
   switch ( arg[i] )
    {
    case '+':
     C_plus_plus = 1;
     break;
    case 'B':
     interactive = 0;
     interactive_given = 1;
     break;
    case 'b':
     backing_up_report = 1;
     break;
    case 'c':
     fprintf( err,
 "%s: Assuming use of deprecated -c flag is really intended to be -C\n",
     program_name );
    case 'C':
     if ( i != 1 )
      flexerror(
     "-C flag must be given separately" );
     if ( ! sawcmpflag )
      {
      useecs = 0;
      usemecs = 0;
      fulltbl = 0;
      sawcmpflag = 1;
      }
     for ( ++i; arg[i] != '\0'; ++i )
      switch ( arg[i] )
       {
       case 'a':
        long_align =
         1;
        break;
       case 'e':
        useecs = 1;
        break;
       case 'F':
        fullspd = 1;
        break;
       case 'f':
        fulltbl = 1;
        break;
       case 'm':
        usemecs = 1;
        break;
       case 'r':
        use_read = 1;
        break;
       default:
        lerrif(
      "unknown -C option '%c'",
        (int) arg[i] );
        break;
       }
     goto get_next_arg;
    case 'd':
     ddebug = 1;
     break;
    case 'f':
     useecs = usemecs = 0;
     use_read = fulltbl = 1;
     break;
    case 'F':
     useecs = usemecs = 0;
     use_read = fullspd = 1;
     break;
    case 'h':
     usage();
     exit( 0 );
    case 'I':
     interactive = 1;
     interactive_given = 1;
     break;
    case 'i':
     caseins = 1;
     break;
    case 'l':
     lex_compat = 1;
     break;
    case 'L':
     gen_line_dirs = 0;
     break;
    case 'n':
     break;
    case 'P':
     if ( i != 1 )
      flexerror(
     "-P flag must be given separately" );
     prefix = arg + i + 1;
     goto get_next_arg;
    case 'p':
     ++performance_report;
     break;
    case 'S':
     if ( i != 1 )
      flexerror(
     "-S flag must be given separately" );
     skelname = arg + i + 1;
     goto get_next_arg;
    case 's':
     spprdflt = 1;
     break;
    case 't':
     use_stdout = 1;
     break;
    case 'T':
     trace = 1;
     break;
    case 'v':
     printstats = 1;
     break;
    case 'V':
     fprintf( err, "%s version %s\n",
      program_name, flex_version );
     exit( 0 );
    case 'w':
     nowarn = 1;
     break;
    case '7':
     csize = 128;
     csize_given = 1;
     break;
    case '8':
     csize = 256;
     csize_given = 1;
     break;
    default:
     fprintf( err,
      "%s: unknown flag '%c'\n",
      program_name, (int) arg[i] );
     usage();
     exit( 1 );
    }
  get_next_arg: ;
  }
 if ( ! csize_given )
  {
  if ( (fulltbl || fullspd) && ! useecs )
   csize = 128;
  else
   csize = 256;
  }
 if ( ! interactive_given )
  {
  if ( fulltbl || fullspd )
   interactive = 0;
  else
   interactive = 1;
  }
 if ( lex_compat )
  {
  if ( C_plus_plus )
   flexerror( "Can't use -+ with -l option" );
  if ( fulltbl || fullspd )
   flexerror( "Can't use -f or -F with -l option" );
  yymore_really_used = reject_really_used = 1;
  yytext_is_array = 1;
  use_read = 0;
  }
 if ( (fulltbl || fullspd) && usemecs )
  flexerror( "-Cf/-CF and -Cm don't make sense together" );
 if ( (fulltbl || fullspd) && interactive )
  flexerror( "-Cf/-CF and -I are incompatible" );
 if ( fulltbl && fullspd )
  flexerror( "-Cf and -CF are mutually exclusive" );
 if ( C_plus_plus && fullspd )
  flexerror( "Can't use -+ with -CF option" );
 if ( ! use_stdout )
  {
  FILE *prev_stdout;
  char *suffix;
  if ( C_plus_plus )
   suffix = "cc";
  else
   suffix = "c";
  sprintf( outfile_path, outfile_template, prefix, suffix );
  prev_stdout = freopen( outfile_path, "w", stdout );
  if ( prev_stdout == ((void *)0) )
   lerrsf( "could not create %s", outfile_path );
  outfile_created = 1;
  }
 num_input_files = argc;
 input_files = argv;
 set_input_file( num_input_files > 0 ? input_files[0] : ((void *)0) );
 if ( backing_up_report )
  {
  backing_up_file = fopen( "lex.backup", "w" );
  if ( backing_up_file == ((void *)0) )
   flexerror( "could not create lex.backup" );
  }
 else
  backing_up_file = ((void *)0);
 lastccl = 0;
 lastsc = 0;
 if ( skelname && (skelfile = fopen( skelname, "r" )) == ((void *)0) )
  lerrsf( "can't open skeleton file %s", skelname );
 if ( strcmp( prefix, "yy" ) )
  {
  printf( "#define yy%s %s%s\n", "FlexLexer", prefix, "FlexLexer" );;
  printf( "#define yy%s %s%s\n", "_create_buffer", prefix, "_create_buffer" );;
  printf( "#define yy%s %s%s\n", "_delete_buffer", prefix, "_delete_buffer" );;
  printf( "#define yy%s %s%s\n", "_flex_debug", prefix, "_flex_debug" );;
  printf( "#define yy%s %s%s\n", "_init_buffer", prefix, "_init_buffer" );;
  printf( "#define yy%s %s%s\n", "_load_buffer_state", prefix, "_load_buffer_state" );;
  printf( "#define yy%s %s%s\n", "_switch_to_buffer", prefix, "_switch_to_buffer" );;
  printf( "#define yy%s %s%s\n", "in", prefix, "in" );;
  printf( "#define yy%s %s%s\n", "leng", prefix, "leng" );;
  printf( "#define yy%s %s%s\n", "lex", prefix, "lex" );;
  printf( "#define yy%s %s%s\n", "out", prefix, "out" );;
  printf( "#define yy%s %s%s\n", "restart", prefix, "restart" );;
  printf( "#define yy%s %s%s\n", "text", prefix, "text" );;
  printf( "#define yy%s %s%s\n", "wrap", prefix, "wrap" );;
  printf( "\n" );
  }
 lastdfa = lastnfa = 0;
 num_rules = num_eof_rules = default_rule = 0;
 numas = numsnpairs = tmpuses = 0;
 numecs = numeps = eps2 = num_reallocs = hshcol = dfaeql = totnst = 0;
 numuniq = numdup = hshsave = eofseen = datapos = dataline = 0;
 num_backing_up = onesp = numprots = 0;
 variable_trailing_context_rules = bol_needed = 0;
 linenum = sectnum = 1;
 firstprot = 0;
 lastprot = 1;
 if ( useecs )
  {
  ecgroup[1] = 0;
  for ( i = 2; i <= csize; ++i )
   {
   ecgroup[i] = i - 1;
   nextecm[i - 1] = i;
   }
  nextecm[csize] = 0;
  }
 else
  {
  for ( i = 1; i <= csize; ++i )
   {
   ecgroup[i] = i;
   nextecm[i] = -32767;
   }
  }
 set_up_initial_allocations();
 }
void readin()
 {
 skelout();
 line_directive_out( (FILE *) 0 );
 if ( yyparse() )
  {
  pinpoint_message( "fatal parse error" );
  flexend( 1 );
  }
 if ( syntaxerror )
  flexend( 1 );
 if ( yymore_really_used == 1 )
  yymore_used = 1;
 else if ( yymore_really_used == 2 )
  yymore_used = 0;
 if ( reject_really_used == 1 )
  reject = 1;
 else if ( reject_really_used == 2 )
  reject = 0;
 if ( performance_report > 0 )
  {
  if ( lex_compat )
   {
   fprintf( err,
"-l AT&T lex compatibility option entails a large performance penalty\n" );
   fprintf( err,
" and may be the actual source of other reported performance penalties\n" );
   }
  if ( performance_report > 1 )
   {
   if ( interactive )
    fprintf( err,
  "-I (interactive) entails a minor performance penalty\n" );
   if ( yymore_used )
    fprintf( err,
   "yymore() entails a minor performance penalty\n" );
   }
  if ( reject )
   fprintf( err,
   "REJECT entails a large performance penalty\n" );
  if ( variable_trailing_context_rules )
   fprintf( err,
"Variable trailing context rules entail a large performance penalty\n" );
  }
 if ( reject )
  real_reject = 1;
 if ( variable_trailing_context_rules )
  reject = 1;
 if ( (fulltbl || fullspd) && reject )
  {
  if ( real_reject )
   flexerror( "REJECT cannot be used with -f or -F" );
  else
   flexerror(
 "variable trailing context rules cannot be used with -f or -F" );
  }
 if ( csize == 256 )
  puts( "typedef unsigned char YY_CHAR;" );
 else
  puts( "typedef char YY_CHAR;" );
 if ( C_plus_plus )
  {
  puts( "#define yytext_ptr yytext" );
  if ( interactive )
   puts( "#define YY_INTERACTIVE" );
  }
 if ( fullspd )
  printf(
  "typedef const struct yy_trans_info *yy_state_type;\n" );
 else if ( ! C_plus_plus )
  printf( "typedef int yy_state_type;\n" );
 if ( reject )
  printf( "\n#define YY_USES_REJECT\n" );
 if ( ddebug )
  puts( "\n#define FLEX_DEBUG" );
 if ( lex_compat )
  {
  printf( "FILE *yyin = stdin, *yyout = stdout;\n" );
  printf( "extern int yylineno;\n" );
  printf( "int yylineno = 1;\n" );
  }
 else if ( ! C_plus_plus )
  printf( "FILE *yyin = (FILE *) 0, *yyout = (FILE *) 0;\n" );
 if ( C_plus_plus )
  printf( "\n#include <FlexLexer.h>\n" );
 else
  {
  if ( yytext_is_array )
   puts( "extern char yytext[];\n" );
  else
   {
   puts( "extern char *yytext;" );
   puts( "#define yytext_ptr yytext" );
   }
  }
 if ( useecs )
  numecs = cre8ecs( nextecm, ecgroup, csize );
 else
  numecs = csize;
 ecgroup[0] = ecgroup[csize];
 NUL_ec = ((ecgroup[0]) < 0 ? -(ecgroup[0]) : (ecgroup[0]));
 if ( useecs )
  ccl2ecl();
 }
void set_up_initial_allocations()
 {
 current_mns = 2000;
 firstst = (int *) allocate_array( current_mns, sizeof( int ) );
 lastst = (int *) allocate_array( current_mns, sizeof( int ) );
 finalst = (int *) allocate_array( current_mns, sizeof( int ) );
 transchar = (int *) allocate_array( current_mns, sizeof( int ) );
 trans1 = (int *) allocate_array( current_mns, sizeof( int ) );
 trans2 = (int *) allocate_array( current_mns, sizeof( int ) );
 accptnum = (int *) allocate_array( current_mns, sizeof( int ) );
 assoc_rule = (int *) allocate_array( current_mns, sizeof( int ) );
 state_type = (int *) allocate_array( current_mns, sizeof( int ) );
 current_max_rules = 100;
 rule_type = (int *) allocate_array( current_max_rules, sizeof( int ) );
 rule_linenum = (int *) allocate_array( current_max_rules, sizeof( int ) );
 rule_useful = (int *) allocate_array( current_max_rules, sizeof( int ) );
 current_max_scs = 40;
 scset = (int *) allocate_array( current_max_scs, sizeof( int ) );
 scbol = (int *) allocate_array( current_max_scs, sizeof( int ) );
 scxclu = (int *) allocate_array( current_max_scs, sizeof( int ) );
 sceof = (int *) allocate_array( current_max_scs, sizeof( int ) );
 scname = (char **) allocate_array( current_max_scs, sizeof( char * ) );
 actvsc = (int *) allocate_array( current_max_scs, sizeof( int ) );
 current_maxccls = 100;
 cclmap = (int *) allocate_array( current_maxccls, sizeof( int ) );
 ccllen = (int *) allocate_array( current_maxccls, sizeof( int ) );
 cclng = (int *) allocate_array( current_maxccls, sizeof( int ) );
 current_max_ccl_tbl_size = 500;
 ccltbl = (unsigned char *) allocate_array( current_max_ccl_tbl_size, sizeof( unsigned char ) );
 current_max_dfa_size = 750;
 current_max_xpairs = 2000;
 nxt = (int *) allocate_array( current_max_xpairs, sizeof( int ) );
 chk = (int *) allocate_array( current_max_xpairs, sizeof( int ) );
 current_max_template_xpairs = 2500;
 tnxt = (int *) allocate_array( current_max_template_xpairs, sizeof( int ) );
 current_max_dfas = 1000;
 base = (int *) allocate_array( current_max_dfas, sizeof( int ) );
 def = (int *) allocate_array( current_max_dfas, sizeof( int ) );
 dfasiz = (int *) allocate_array( current_max_dfas, sizeof( int ) );
 accsiz = (int *) allocate_array( current_max_dfas, sizeof( int ) );
 dhash = (int *) allocate_array( current_max_dfas, sizeof( int ) );
 dss = (int **) allocate_array( current_max_dfas, sizeof( int * ) );
 dfaacc = (union dfaacc_union *) allocate_array( current_max_dfas, sizeof( union dfaacc_union ) );
 nultrans = (int *) 0;
 }
void usage()
 {
 fprintf( err,
"%s [-bcdfhilnpstvwBFILTV78+ -C[aefFmr] -Pprefix -Sskeleton] [file ...]\n",
  program_name );
 fprintf( err,
  "\t-b  generate backing-up information to lex.backup\n" );
 fprintf( err, "\t-c  do-nothing POSIX option\n" );
 fprintf( err, "\t-d  turn on debug mode in generated scanner\n" );
 fprintf( err, "\t-f  generate fast, large scanner\n" );
 fprintf( err, "\t-h  produce this help message\n" );
 fprintf( err, "\t-i  generate case-insensitive scanner\n" );
 fprintf( err, "\t-l  maximal compatibility with original lex\n" );
 fprintf( err, "\t-n  do-nothing POSIX option\n" );
 fprintf( err, "\t-p  generate performance report to stderr\n" );
 fprintf( err,
  "\t-s  suppress default rule to ECHO unmatched text\n" );
 fprintf( err,
 "\t-t  write generated scanner on stdout instead of lex.yy.c\n" );
 fprintf( err,
  "\t-v  write summary of scanner statistics to stderr\n" );
 fprintf( err, "\t-w  do not generate warnings\n" );
 fprintf( err, "\t-B  generate batch scanner (opposite of -I)\n" );
 fprintf( err,
  "\t-F  use alternative fast scanner representation\n" );
 fprintf( err,
  "\t-I  generate interactive scanner (opposite of -B)\n" );
 fprintf( err, "\t-L  suppress #line directives in scanner\n" );
 fprintf( err, "\t-T  %s should run in trace mode\n", program_name );
 fprintf( err, "\t-V  report %s version\n", program_name );
 fprintf( err, "\t-7  generate 7-bit scanner\n" );
 fprintf( err, "\t-8  generate 8-bit scanner\n" );
 fprintf( err, "\t-+  generate C++ scanner class\n" );
 fprintf( err,
 "\t-C  specify degree of table compression (default is -Cem):\n" );
 fprintf( err,
 "\t\t-Ca  trade off larger tables for better memory alignment\n" );
 fprintf( err, "\t\t-Ce  construct equivalence classes\n" );
 fprintf( err,
 "\t\t-Cf  do not compress scanner tables; use -f representation\n" );
 fprintf( err,
 "\t\t-CF  do not compress scanner tables; use -F representation\n" );
 fprintf( err, "\t\t-Cm  construct meta-equivalence classes\n" );
 fprintf( err,
  "\t\t-Cr  use read() instead of stdio for scanner input\n" );
 fprintf( err, "\t-P  specify scanner prefix other than \"yy\"\n" );
 fprintf( err, "\t-S  specify skeleton file\n" );
 }
void ccladd( cclp, ch )
int cclp;
int ch;
 {
 int ind, len, newpos, i;
 check_char( ch );
 len = ccllen[cclp];
 ind = cclmap[cclp];
 for ( i = 0; i < len; ++i )
  if ( ccltbl[ind + i] == ch )
   return;
 newpos = ind + len;
 if ( newpos >= current_max_ccl_tbl_size )
  {
  current_max_ccl_tbl_size += 250;
  ++num_reallocs;
  ccltbl = (unsigned char *) reallocate_array( (void *) ccltbl, current_max_ccl_tbl_size, sizeof( unsigned char ) );
  }
 ccllen[cclp] = len + 1;
 ccltbl[newpos] = ch;
 }
int cclinit()
 {
 if ( ++lastccl >= current_maxccls )
  {
  current_maxccls += 100;
  ++num_reallocs;
  cclmap = (int *) reallocate_array( (void *) cclmap, current_maxccls, sizeof( int ) );
  ccllen = (int *) reallocate_array( (void *) ccllen, current_maxccls, sizeof( int ) );
  cclng = (int *) reallocate_array( (void *) cclng, current_maxccls, sizeof( int ) );
  }
 if ( lastccl == 1 )
  cclmap[lastccl] = 0;
 else
  cclmap[lastccl] = cclmap[lastccl - 1] + ccllen[lastccl - 1];
 ccllen[lastccl] = 0;
 cclng[lastccl] = 0;
 return lastccl;
 }
void cclnegate( cclp )
int cclp;
 {
 cclng[cclp] = 1;
 }
void list_character_set( file, cset )
FILE *file;
int cset[];
 {
 register int i;
 _IO_putc ('[', file);
 for ( i = 0; i < csize; ++i )
  {
  if ( cset[i] )
   {
   register int start_char = i;
   _IO_putc (' ', file);
   fputs( readable_form( i ), file );
   while ( ++i < csize && cset[i] )
    ;
   if ( i - 1 > start_char )
    fprintf( file, "-%s", readable_form( i - 1 ) );
   _IO_putc (' ', file);
   }
  }
 _IO_putc (']', file);
 }
void dump_associated_rules (FILE*, int);
void dump_transitions (FILE*, int[]);
void sympartition (int[], int, int[], int[]);
int symfollowset (int[], int, int, int[]);
void check_for_backing_up( ds, state )
int ds;
int state[];
 {
 if ( (reject && ! dfaacc[ds].dfaacc_set) ||
      (! reject && ! dfaacc[ds].dfaacc_state) )
  {
  ++num_backing_up;
  if ( backing_up_report )
   {
   fprintf( backing_up_file,
    "State #%d is non-accepting -\n", ds );
   dump_associated_rules( backing_up_file, ds );
   dump_transitions( backing_up_file, state );
   _IO_putc ('\n', backing_up_file);
   }
  }
 }
void check_trailing_context( nfa_states, num_states, accset, nacc )
int *nfa_states, num_states;
int *accset;
register int nacc;
 {
 register int i, j;
 for ( i = 1; i <= num_states; ++i )
  {
  int ns = nfa_states[i];
  register int type = state_type[ns];
  register int ar = assoc_rule[ns];
  if ( type == 0x1 || rule_type[ar] != 1 )
   {
   }
  else if ( type == 0x2 )
   {
   for ( j = 1; j <= nacc; ++j )
    if ( accset[j] & 0x4000 )
     {
     line_warning(
      "dangerous trailing context",
      rule_linenum[ar] );
     return;
     }
   }
  }
 }
void dump_associated_rules( file, ds )
FILE *file;
int ds;
 {
 register int i, j;
 register int num_associated_rules = 0;
 int rule_set[100 + 1];
 int *dset = dss[ds];
 int size = dfasiz[ds];
 for ( i = 1; i <= size; ++i )
  {
  register int rule_num = rule_linenum[assoc_rule[dset[i]]];
  for ( j = 1; j <= num_associated_rules; ++j )
   if ( rule_num == rule_set[j] )
    break;
  if ( j > num_associated_rules )
   {
   if ( num_associated_rules < 100 )
    rule_set[++num_associated_rules] = rule_num;
   }
  }
 bubble( rule_set, num_associated_rules );
 fprintf( file, " associated rule line numbers:" );
 for ( i = 1; i <= num_associated_rules; ++i )
  {
  if ( i % 8 == 1 )
   _IO_putc ('\n', file);
  fprintf( file, "\t%d", rule_set[i] );
  }
 _IO_putc ('\n', file);
 }
void dump_transitions( file, state )
FILE *file;
int state[];
 {
 register int i, ec;
 int out_char_set[256];
 for ( i = 0; i < csize; ++i )
  {
  ec = ((ecgroup[i]) < 0 ? -(ecgroup[i]) : (ecgroup[i]));
  out_char_set[i] = state[ec];
  }
 fprintf( file, " out-transitions: " );
 list_character_set( file, out_char_set );
 for ( i = 0; i < csize; ++i )
  out_char_set[i] = ! out_char_set[i];
 fprintf( file, "\n jam-transitions: EOF " );
 list_character_set( file, out_char_set );
 _IO_putc ('\n', file);
 }
int *epsclosure( t, ns_addr, accset, nacc_addr, hv_addr )
int *t, *ns_addr, accset[], *nacc_addr, *hv_addr;
 {
 register int stkpos, ns, tsp;
 int numstates = *ns_addr, nacc, hashval, transsym, nfaccnum;
 int stkend, nstate;
 static int did_stk_init = 0, *stk;
 if ( ! did_stk_init )
  {
  stk = (int *) allocate_array( current_max_dfa_size, sizeof( int ) );
  did_stk_init = 1;
  }
 nacc = stkend = hashval = 0;
 for ( nstate = 1; nstate <= numstates; ++nstate )
  {
  ns = t[nstate];
  if ( ! (trans1[ns] < 0) )
   {
   { if ( ++stkend >= current_max_dfa_size ) { current_max_dfa_size += 750; ++num_reallocs; t = (int *) reallocate_array( (void *) t, current_max_dfa_size, sizeof( int ) ); stk = (int *) reallocate_array( (void *) stk, current_max_dfa_size, sizeof( int ) ); } stk[stkend] = ns; trans1[ns] = trans1[ns] - 32000; }
   { nfaccnum = accptnum[ns]; if ( nfaccnum != 0 ) accset[++nacc] = nfaccnum; }
   hashval += ns;
   }
  }
 for ( stkpos = 1; stkpos <= stkend; ++stkpos )
  {
  ns = stk[stkpos];
  transsym = transchar[ns];
  if ( transsym == (256 + 1) )
   {
   tsp = trans1[ns] + 32000;
   if ( tsp != 0 )
    {
    if ( ! (trans1[tsp] < 0) )
     { { if ( ++stkend >= current_max_dfa_size ) { current_max_dfa_size += 750; ++num_reallocs; t = (int *) reallocate_array( (void *) t, current_max_dfa_size, sizeof( int ) ); stk = (int *) reallocate_array( (void *) stk, current_max_dfa_size, sizeof( int ) ); } stk[stkend] = tsp; trans1[tsp] = trans1[tsp] - 32000; } { nfaccnum = accptnum[tsp]; if ( nfaccnum != 0 ) accset[++nacc] = nfaccnum; } if ( nfaccnum != 0 || transchar[tsp] != (256 + 1) ) { if ( ++numstates >= current_max_dfa_size ) { current_max_dfa_size += 750; ++num_reallocs; t = (int *) reallocate_array( (void *) t, current_max_dfa_size, sizeof( int ) ); stk = (int *) reallocate_array( (void *) stk, current_max_dfa_size, sizeof( int ) ); } t[numstates] = tsp; hashval += tsp; } }
    tsp = trans2[ns];
    if ( tsp != 0 && ! (trans1[tsp] < 0) )
     { { if ( ++stkend >= current_max_dfa_size ) { current_max_dfa_size += 750; ++num_reallocs; t = (int *) reallocate_array( (void *) t, current_max_dfa_size, sizeof( int ) ); stk = (int *) reallocate_array( (void *) stk, current_max_dfa_size, sizeof( int ) ); } stk[stkend] = tsp; trans1[tsp] = trans1[tsp] - 32000; } { nfaccnum = accptnum[tsp]; if ( nfaccnum != 0 ) accset[++nacc] = nfaccnum; } if ( nfaccnum != 0 || transchar[tsp] != (256 + 1) ) { if ( ++numstates >= current_max_dfa_size ) { current_max_dfa_size += 750; ++num_reallocs; t = (int *) reallocate_array( (void *) t, current_max_dfa_size, sizeof( int ) ); stk = (int *) reallocate_array( (void *) stk, current_max_dfa_size, sizeof( int ) ); } t[numstates] = tsp; hashval += tsp; } }
    }
   }
  }
 for ( stkpos = 1; stkpos <= stkend; ++stkpos )
  {
  if ( (trans1[stk[stkpos]] < 0) )
   trans1[stk[stkpos]] = trans1[stk[stkpos]] + 32000;
  else
   flexfatal( "consistency check failed in epsclosure()" );
  }
 *ns_addr = numstates;
 *hv_addr = hashval;
 *nacc_addr = nacc;
 return t;
 }
void increase_max_dfas()
 {
 current_max_dfas += 1000;
 ++num_reallocs;
 base = (int *) reallocate_array( (void *) base, current_max_dfas, sizeof( int ) );
 def = (int *) reallocate_array( (void *) def, current_max_dfas, sizeof( int ) );
 dfasiz = (int *) reallocate_array( (void *) dfasiz, current_max_dfas, sizeof( int ) );
 accsiz = (int *) reallocate_array( (void *) accsiz, current_max_dfas, sizeof( int ) );
 dhash = (int *) reallocate_array( (void *) dhash, current_max_dfas, sizeof( int ) );
 dss = (int **) reallocate_array( (void *) dss, current_max_dfas, sizeof( int * ) );
 dfaacc = (union dfaacc_union *) reallocate_array( (void *) dfaacc, current_max_dfas, sizeof( union dfaacc_union ) );
 if ( nultrans )
  nultrans =
   (int *) reallocate_array( (void *) nultrans, current_max_dfas, sizeof( int ) );
 }
void ntod()
 {
 int *accset, ds, nacc, newds;
 int sym, hashval, numstates, dsize;
 int num_full_table_rows;
 int *nset, *dset;
 int targptr, totaltrans, i, comstate, comfreq, targ;
 int *epsclosure(), snstods(), symlist[256 + 1];
 int num_start_states;
 int todo_head, todo_next;
 int duplist[256 + 1], state[256 + 1];
 int targfreq[256 + 1], targstate[256 + 1];
 accset = (int *) allocate_array( num_rules + 1, sizeof( int ) );
 nset = (int *) allocate_array( current_max_dfa_size, sizeof( int ) );
 todo_head = todo_next = 0;
 for ( i = 0; i <= csize; ++i )
  {
  duplist[i] = 0;
  symlist[i] = 0;
  }
 for ( i = 0; i <= num_rules; ++i )
  accset[i] = 0;
 if ( trace )
  {
  dumpnfa( scset[1] );
  fputs( "\n\nDFA Dump:\n\n", err );
  }
 inittbl();
 if ( ! fullspd && ecgroup[0] == numecs )
  {
  int use_NUL_table = (numecs == csize);
  if ( fulltbl && ! use_NUL_table )
   {
   int power_of_two;
   for ( power_of_two = 1; power_of_two <= csize;
         power_of_two *= 2 )
    if ( numecs == power_of_two )
     {
     use_NUL_table = 1;
     break;
     }
   }
  if ( use_NUL_table )
   nultrans = (int *) allocate_array( current_max_dfas, sizeof( int ) );
  }
 if ( fullspd )
  {
  for ( i = 0; i <= numecs; ++i )
   state[i] = 0;
  place_state( state, 0, 0 );
  dfaacc[i].dfaacc_state = 0;
  }
 else if ( fulltbl )
  {
  if ( nultrans )
   num_full_table_rows = numecs;
  else
   num_full_table_rows = numecs + 1;
  printf( "static const %s yy_nxt[][%d] =\n    {\n",
   long_align ? "long" : "short", num_full_table_rows );
  for ( i = 0; i < num_full_table_rows; ++i )
   mk2data( 0 );
  datapos = 10;
  dataline = 10;
  }
 num_start_states = lastsc * 2;
 for ( i = 1; i <= num_start_states; ++i )
  {
  numstates = 1;
  if ( i % 2 == 1 )
   nset[numstates] = scset[(i / 2) + 1];
  else
   nset[numstates] =
    mkbranch( scbol[i / 2], scset[i / 2] );
  nset = epsclosure( nset, &numstates, accset, &nacc, &hashval );
  if ( snstods( nset, numstates, accset, nacc, hashval, &ds ) )
   {
   numas += nacc;
   totnst += numstates;
   ++todo_next;
   if ( variable_trailing_context_rules && nacc > 0 )
    check_trailing_context( nset, numstates,
       accset, nacc );
   }
  }
 if ( ! fullspd )
  {
  if ( ! snstods( nset, 0, accset, 0, 0, &end_of_buffer_state ) )
   flexfatal(
    "could not create unique end-of-buffer state" );
  ++numas;
  ++num_start_states;
  ++todo_next;
  }
 while ( todo_head < todo_next )
  {
  targptr = 0;
  totaltrans = 0;
  for ( i = 1; i <= numecs; ++i )
   state[i] = 0;
  ds = ++todo_head;
  dset = dss[ds];
  dsize = dfasiz[ds];
  if ( trace )
   fprintf( err, "state # %d:\n", ds );
  sympartition( dset, dsize, symlist, duplist );
  for ( sym = 1; sym <= numecs; ++sym )
   {
   if ( symlist[sym] )
    {
    symlist[sym] = 0;
    if ( duplist[sym] == 0 )
     {
     numstates = symfollowset( dset, dsize,
        sym, nset );
     nset = epsclosure( nset, &numstates,
      accset, &nacc, &hashval );
     if ( snstods( nset, numstates, accset,
      nacc, hashval, &newds ) )
      {
      totnst = totnst + numstates;
      ++todo_next;
      numas += nacc;
      if (
     variable_trailing_context_rules &&
       nacc > 0 )
       check_trailing_context(
        nset, numstates,
        accset, nacc );
      }
     state[sym] = newds;
     if ( trace )
      fprintf( err, "\t%d\t%d\n",
       sym, newds );
     targfreq[++targptr] = 1;
     targstate[targptr] = newds;
     ++numuniq;
     }
    else
     {
     targ = state[duplist[sym]];
     state[sym] = targ;
     if ( trace )
      fprintf( err, "\t%d\t%d\n",
       sym, targ );
     i = 0;
     while ( targstate[++i] != targ )
      ;
     ++targfreq[i];
     ++numdup;
     }
    ++totaltrans;
    duplist[sym] = 0;
    }
   }
  numsnpairs = numsnpairs + totaltrans;
  if ( caseins && ! useecs )
   {
   register int j;
   for ( i = 'A', j = 'a'; i <= 'Z'; ++i, ++j )
    state[i] = state[j];
   }
  if ( ds > num_start_states )
   check_for_backing_up( ds, state );
  if ( nultrans )
   {
   nultrans[ds] = state[NUL_ec];
   state[NUL_ec] = 0;
   }
  if ( fulltbl )
   {
   if ( ds == end_of_buffer_state )
    mk2data( -end_of_buffer_state );
   else
    mk2data( end_of_buffer_state );
   for ( i = 1; i < num_full_table_rows; ++i )
    mk2data( state[i] ? state[i] : -ds );
   datapos = 10;
   dataline = 10;
   }
  else if ( fullspd )
   place_state( state, ds, totaltrans );
  else if ( ds == end_of_buffer_state )
   stack1( ds, 0, 0, -32766 );
  else
   {
   comfreq = 0;
   comstate = 0;
   for ( i = 1; i <= targptr; ++i )
    if ( targfreq[i] > comfreq )
     {
     comfreq = targfreq[i];
     comstate = targstate[i];
     }
   bldtbl( state, ds, totaltrans, comstate, comfreq );
   }
  }
 if ( fulltbl )
  dataend();
 else if ( ! fullspd )
  {
  cmptmps();
  while ( onesp > 0 )
   {
   mk1tbl( onestate[onesp], onesym[onesp], onenext[onesp],
   onedef[onesp] );
   --onesp;
   }
  mkdeftbl();
  }
 flex_free( (void *) accset );
 flex_free( (void *) nset );
 }
int snstods( sns, numstates, accset, nacc, hashval, newds_addr )
int sns[], numstates, accset[], nacc, hashval, *newds_addr;
 {
 int didsort = 0;
 register int i, j;
 int newds, *oldsns;
 for ( i = 1; i <= lastdfa; ++i )
  if ( hashval == dhash[i] )
   {
   if ( numstates == dfasiz[i] )
    {
    oldsns = dss[i];
    if ( ! didsort )
     {
     bubble( sns, numstates );
     didsort = 1;
     }
    for ( j = 1; j <= numstates; ++j )
     if ( sns[j] != oldsns[j] )
      break;
    if ( j > numstates )
     {
     ++dfaeql;
     *newds_addr = i;
     return 0;
     }
    ++hshcol;
    }
   else
    ++hshsave;
   }
 if ( ++lastdfa >= current_max_dfas )
  increase_max_dfas();
 newds = lastdfa;
 dss[newds] = (int *) allocate_array( numstates + 1, sizeof( int ) );
 if ( ! didsort )
  bubble( sns, numstates );
 for ( i = 1; i <= numstates; ++i )
  dss[newds][i] = sns[i];
 dfasiz[newds] = numstates;
 dhash[newds] = hashval;
 if ( nacc == 0 )
  {
  if ( reject )
   dfaacc[newds].dfaacc_set = (int *) 0;
  else
   dfaacc[newds].dfaacc_state = 0;
  accsiz[newds] = 0;
  }
 else if ( reject )
  {
  bubble( accset, nacc );
  dfaacc[newds].dfaacc_set = (int *) allocate_array( nacc + 1, sizeof( int ) );
  for ( i = 1; i <= nacc; ++i )
   {
   dfaacc[newds].dfaacc_set[i] = accset[i];
   if ( accset[i] <= num_rules )
    rule_useful[accset[i]] = 1;
   }
  accsiz[newds] = nacc;
  }
 else
  {
  j = num_rules + 1;
  for ( i = 1; i <= nacc; ++i )
   if ( accset[i] < j )
    j = accset[i];
  dfaacc[newds].dfaacc_state = j;
  if ( j <= num_rules )
   rule_useful[j] = 1;
  }
 *newds_addr = newds;
 return 1;
 }
int symfollowset( ds, dsize, transsym, nset )
int ds[], dsize, transsym, nset[];
 {
 int ns, tsp, sym, i, j, lenccl, ch, numstates, ccllist;
 numstates = 0;
 for ( i = 1; i <= dsize; ++i )
  {
  ns = ds[i];
  sym = transchar[ns];
  tsp = trans1[ns];
  if ( sym < 0 )
   {
   sym = -sym;
   ccllist = cclmap[sym];
   lenccl = ccllen[sym];
   if ( cclng[sym] )
    {
    for ( j = 0; j < lenccl; ++j )
     {
     ch = ccltbl[ccllist + j];
     if ( ch == 0 )
      ch = NUL_ec;
     if ( ch > transsym )
      break;
     else if ( ch == transsym )
                   goto bottom;
     }
    nset[++numstates] = tsp;
    }
   else
    for ( j = 0; j < lenccl; ++j )
     {
     ch = ccltbl[ccllist + j];
     if ( ch == 0 )
      ch = NUL_ec;
     if ( ch > transsym )
      break;
     else if ( ch == transsym )
      {
      nset[++numstates] = tsp;
      break;
      }
     }
   }
  else if ( sym >= 'A' && sym <= 'Z' && caseins )
   flexfatal( "consistency check failed in symfollowset" );
  else if ( sym == (256 + 1) )
   {
   }
  else if ( ((ecgroup[sym]) < 0 ? -(ecgroup[sym]) : (ecgroup[sym])) == transsym )
   nset[++numstates] = tsp;
  bottom: ;
  }
 return numstates;
 }
void sympartition( ds, numstates, symlist, duplist )
int ds[], numstates;
int symlist[], duplist[];
 {
 int tch, i, j, k, ns, dupfwd[256 + 1], lenccl, cclp, ich;
 for ( i = 1; i <= numecs; ++i )
  {
  duplist[i] = i - 1;
  dupfwd[i] = i + 1;
  }
 duplist[1] = 0;
 dupfwd[numecs] = 0;
 for ( i = 1; i <= numstates; ++i )
  {
  ns = ds[i];
  tch = transchar[ns];
  if ( tch != (256 + 1) )
   {
   if ( tch < -lastccl || tch >= csize )
    {
    flexfatal(
   "bad transition character detected in sympartition()" );
    }
   if ( tch >= 0 )
    {
    int ec = ecgroup[tch];
    mkechar( ec, dupfwd, duplist );
    symlist[ec] = 1;
    }
   else
    {
    tch = -tch;
    lenccl = ccllen[tch];
    cclp = cclmap[tch];
    mkeccl( ccltbl + cclp, lenccl, dupfwd,
     duplist, numecs, NUL_ec );
    if ( cclng[tch] )
     {
     j = 0;
     for ( k = 0; k < lenccl; ++k )
      {
      ich = ccltbl[cclp + k];
      if ( ich == 0 )
       ich = NUL_ec;
      for ( ++j; j < ich; ++j )
       symlist[j] = 1;
      }
     for ( ++j; j <= numecs; ++j )
      symlist[j] = 1;
     }
    else
     for ( k = 0; k < lenccl; ++k )
      {
      ich = ccltbl[cclp + k];
      if ( ich == 0 )
       ich = NUL_ec;
      symlist[ich] = 1;
      }
    }
   }
  }
 }
void ccl2ecl()
 {
 int i, ich, newlen, cclp, ccls, cclmec;
 for ( i = 1; i <= lastccl; ++i )
  {
  newlen = 0;
  cclp = cclmap[i];
  for ( ccls = 0; ccls < ccllen[i]; ++ccls )
   {
   ich = ccltbl[cclp + ccls];
   cclmec = ecgroup[ich];
   if ( cclmec > 0 )
    {
    ccltbl[cclp + newlen] = cclmec;
    ++newlen;
    }
   }
  ccllen[i] = newlen;
  }
 }
int cre8ecs( fwd, bck, num )
int fwd[], bck[], num;
 {
 int i, j, numcl;
 numcl = 0;
 for ( i = 1; i <= num; ++i )
  if ( bck[i] == 0 )
   {
   bck[i] = ++numcl;
   for ( j = fwd[i]; j != 0; j = fwd[j] )
    bck[j] = -numcl;
   }
 return numcl;
 }
void mkeccl( ccls, lenccl, fwd, bck, llsiz, NUL_mapping )
unsigned char ccls[];
int lenccl, fwd[], bck[], llsiz, NUL_mapping;
 {
 int cclp, oldec, newec;
 int cclm, i, j;
 static unsigned char cclflags[256];
 cclp = 0;
 while ( cclp < lenccl )
  {
  cclm = ccls[cclp];
  if ( NUL_mapping && cclm == 0 )
   cclm = NUL_mapping;
  oldec = bck[cclm];
  newec = cclm;
  j = cclp + 1;
  for ( i = fwd[cclm]; i != 0 && i <= llsiz; i = fwd[i] )
   {
   for ( ; j < lenccl; ++j )
    {
    register int ccl_char;
    if ( NUL_mapping && ccls[j] == 0 )
     ccl_char = NUL_mapping;
    else
     ccl_char = ccls[j];
    if ( ccl_char > i )
     break;
    if ( ccl_char == i && ! cclflags[j] )
     {
     bck[i] = newec;
     fwd[newec] = i;
     newec = i;
     cclflags[j] = 1;
     goto next_pt;
     }
    }
   bck[i] = oldec;
   if ( oldec != 0 )
    fwd[oldec] = i;
   oldec = i;
   next_pt: ;
   }
  if ( bck[cclm] != 0 || oldec != bck[cclm] )
   {
   bck[cclm] = 0;
   fwd[oldec] = 0;
   }
  fwd[newec] = 0;
  for ( ++cclp; cclflags[cclp] && cclp < lenccl; ++cclp )
   {
   cclflags[cclp] = 0;
   }
  }
 }
void mkechar( tch, fwd, bck )
int tch, fwd[], bck[];
 {
 if ( fwd[tch] != 0 )
  bck[fwd[tch]] = bck[tch];
 if ( bck[tch] != 0 )
  fwd[bck[tch]] = fwd[tch];
 fwd[tch] = 0;
 bck[tch] = 0;
 }
void gen_next_state (int);
void genecs (void);
void indent_put2s (char [], char []);
void indent_puts (char []);
static int indent_level = 0;
static char C_int_decl[] = "static const int %s[%d] =\n    {   0,\n";
static char C_short_decl[] = "static const short int %s[%d] =\n    {   0,\n";
static char C_long_decl[] = "static const long int %s[%d] =\n    {   0,\n";
static char C_state_decl[] =
 "static const yy_state_type %s[%d] =\n    {   0,\n";
void do_indent()
 {
 register int i = indent_level * 8;
 while ( i >= 8 )
  {
  putchar( '\t' );
  i -= 8;
  }
 while ( i > 0 )
  {
  putchar( ' ' );
  --i;
  }
 }
void gen_backing_up()
 {
 if ( reject || num_backing_up == 0 )
  return;
 if ( fullspd )
  indent_puts( "if ( yy_current_state[-1].yy_nxt )" );
 else
  indent_puts( "if ( yy_accept[yy_current_state] )" );
 (++indent_level);
 indent_puts( "{" );
 indent_puts( "yy_last_accepting_state = yy_current_state;" );
 indent_puts( "yy_last_accepting_cpos = yy_cp;" );
 indent_puts( "}" );
 (--indent_level);
 }
void gen_bu_action()
 {
 if ( reject || num_backing_up == 0 )
  return;
 indent_level = 3;
 indent_puts( "case 0: /* must back up */" );
 indent_puts( "/* undo the effects of YY_DO_BEFORE_ACTION */" );
 indent_puts( "*yy_cp = yy_hold_char;" );
 if ( fullspd || fulltbl )
  indent_puts( "yy_cp = yy_last_accepting_cpos + 1;" );
 else
  indent_puts( "yy_cp = yy_last_accepting_cpos;" );
 indent_puts( "yy_current_state = yy_last_accepting_state;" );
 indent_puts( "goto yy_find_action;" );
 putchar( '\n' );
 indent_level = 0;
 }
void genctbl()
 {
 register int i;
 int end_of_buffer_action = num_rules + 1;
 printf( "static const struct yy_trans_info yy_transition[%d] =\n",
  tblend + numecs + 1 );
 printf( "    {\n" );
 while ( tblend + 2 >= current_max_xpairs )
  expand_nxt_chk();
 while ( lastdfa + 1 >= current_max_dfas )
  increase_max_dfas();
 base[lastdfa + 1] = tblend + 2;
 nxt[tblend + 1] = end_of_buffer_action;
 chk[tblend + 1] = numecs + 1;
 chk[tblend + 2] = 1;
 nxt[tblend + 2] = 0;
 for ( i = 0; i <= lastdfa; ++i )
  {
  int anum = dfaacc[i].dfaacc_state;
  int offset = base[i];
  chk[offset] = -1;
  chk[offset - 1] = -2;
  nxt[offset - 1] = anum;
  }
 for ( i = 0; i <= tblend; ++i )
  {
  if ( chk[i] == -1 )
   transition_struct_out( 0, base[lastdfa + 1] - i );
  else if ( chk[i] == -2 )
   transition_struct_out( 0, nxt[i] );
  else if ( chk[i] > numecs || chk[i] == 0 )
   transition_struct_out( 0, 0 );
  else
   transition_struct_out( chk[i],
      base[nxt[i]] - (i - chk[i]) );
  }
 transition_struct_out( chk[tblend + 1], nxt[tblend + 1] );
 transition_struct_out( chk[tblend + 2], nxt[tblend + 2] );
 printf( "    };\n" );
 printf( "\n" );
 printf(
 "static const struct yy_trans_info *yy_start_state_list[%d] =\n",
  lastsc * 2 + 1 );
 printf( "    {\n" );
 for ( i = 0; i <= lastsc * 2; ++i )
  printf( "    &yy_transition[%d],\n", base[i] );
 dataend();
 if ( useecs )
  genecs();
 }
void genecs()
 {
 unsigned char clower();
 register int i, j;
 int numrows;
 printf( C_int_decl, "yy_ec", csize );
 for ( i = 1; i < csize; ++i )
  {
  if ( caseins && (i >= 'A') && (i <= 'Z') )
   ecgroup[i] = ecgroup[clower( i )];
  ecgroup[i] = ((ecgroup[i]) < 0 ? -(ecgroup[i]) : (ecgroup[i]));
  mkdata( ecgroup[i] );
  }
 dataend();
 if ( trace )
  {
  fputs( "\n\nEquivalence Classes:\n\n", err );
  numrows = csize / 8;
  for ( j = 0; j < numrows; ++j )
   {
   for ( i = j; i < csize; i = i + numrows )
    {
    fprintf( err, "%4s = %-2d",
     readable_form( i ), ecgroup[i] );
    _IO_putc (' ', err);
    }
   _IO_putc ('\n', err);
   }
  }
 }
void gen_find_action()
 {
 if ( fullspd )
  indent_puts( "yy_act = yy_current_state[-1].yy_nxt;" );
 else if ( fulltbl )
  indent_puts( "yy_act = yy_accept[yy_current_state];" );
 else if ( reject )
  {
  indent_puts( "yy_current_state = *--yy_state_ptr;" );
  indent_puts( "yy_lp = yy_accept[yy_current_state];" );
  puts(
  "find_rule: /* we branch to this label when backing up */" );
  indent_puts(
  "for ( ; ; ) /* until we find what rule we matched */" );
  (++indent_level);
  indent_puts( "{" );
  indent_puts(
  "if ( yy_lp && yy_lp < yy_accept[yy_current_state + 1] )" );
  (++indent_level);
  indent_puts( "{" );
  indent_puts( "yy_act = yy_acclist[yy_lp];" );
  if ( variable_trailing_context_rules )
   {
   indent_puts( "if ( yy_act & YY_TRAILING_HEAD_MASK ||" );
   indent_puts( "     yy_looking_for_trail_begin )" );
   (++indent_level);
   indent_puts( "{" );
   indent_puts(
    "if ( yy_act == yy_looking_for_trail_begin )" );
   (++indent_level);
   indent_puts( "{" );
   indent_puts( "yy_looking_for_trail_begin = 0;" );
   indent_puts( "yy_act &= ~YY_TRAILING_HEAD_MASK;" );
   indent_puts( "break;" );
   indent_puts( "}" );
   (--indent_level);
   indent_puts( "}" );
   (--indent_level);
   indent_puts( "else if ( yy_act & YY_TRAILING_MASK )" );
   (++indent_level);
   indent_puts( "{" );
   indent_puts(
  "yy_looking_for_trail_begin = yy_act & ~YY_TRAILING_MASK;" );
   indent_puts(
  "yy_looking_for_trail_begin |= YY_TRAILING_HEAD_MASK;" );
   if ( real_reject )
    {
    indent_puts( "yy_full_match = yy_cp;" );
    indent_puts( "yy_full_state = yy_state_ptr;" );
    indent_puts( "yy_full_lp = yy_lp;" );
    }
   indent_puts( "}" );
   (--indent_level);
   indent_puts( "else" );
   (++indent_level);
   indent_puts( "{" );
   indent_puts( "yy_full_match = yy_cp;" );
   indent_puts( "yy_full_state = yy_state_ptr;" );
   indent_puts( "yy_full_lp = yy_lp;" );
   indent_puts( "break;" );
   indent_puts( "}" );
   (--indent_level);
   indent_puts( "++yy_lp;" );
   indent_puts( "goto find_rule;" );
   }
  else
  {
  (++indent_level);
  indent_puts( "{" );
  indent_puts( "yy_full_match = yy_cp;" );
  indent_puts( "break;" );
  indent_puts( "}" );
  (--indent_level);
  }
  indent_puts( "}" );
  (--indent_level);
  indent_puts( "--yy_cp;" );
  indent_puts( "yy_current_state = *--yy_state_ptr;" );
  indent_puts( "yy_lp = yy_accept[yy_current_state];" );
  indent_puts( "}" );
  (--indent_level);
  }
 else
  indent_puts( "yy_act = yy_accept[yy_current_state];" );
 }
void genftbl()
 {
 register int i;
 int end_of_buffer_action = num_rules + 1;
 printf( long_align ? C_long_decl : C_short_decl,
  "yy_accept", lastdfa + 1 );
 dfaacc[end_of_buffer_state].dfaacc_state = end_of_buffer_action;
 for ( i = 1; i <= lastdfa; ++i )
  {
  register int anum = dfaacc[i].dfaacc_state;
  mkdata( anum );
  if ( trace && anum )
   fprintf( err, "state # %d accepts: [%d]\n",
    i, anum );
  }
 dataend();
 if ( useecs )
  genecs();
 }
void gen_next_compressed_state( char_map )
char *char_map;
 {
 indent_put2s( "register YY_CHAR yy_c = %s;", char_map );
 gen_backing_up();
 indent_puts(
"while ( yy_chk[yy_base[yy_current_state] + yy_c] != yy_current_state )" );
 (++indent_level);
 indent_puts( "{" );
 indent_puts( "yy_current_state = (int) yy_def[yy_current_state];" );
 if ( usemecs )
  {
  do_indent();
  printf( "if ( yy_current_state >= %d )\n", lastdfa + 2 );
  (++indent_level);
  indent_puts( "yy_c = yy_meta[(unsigned int) yy_c];" );
  (--indent_level);
  }
 indent_puts( "}" );
 (--indent_level);
 indent_puts(
"yy_current_state = yy_nxt[yy_base[yy_current_state] + (unsigned int) yy_c];" );
 }
void gen_next_match()
 {
 char *char_map = useecs ?
    "yy_ec[YY_SC_TO_UI(*yy_cp)]" :
    "YY_SC_TO_UI(*yy_cp)";
 char *char_map_2 = useecs ?
    "yy_ec[YY_SC_TO_UI(*++yy_cp)]" :
    "YY_SC_TO_UI(*++yy_cp)";
 if ( fulltbl )
  {
  indent_put2s(
 "while ( (yy_current_state = yy_nxt[yy_current_state][%s]) > 0 )",
    char_map );
  (++indent_level);
  if ( num_backing_up > 0 )
   {
   indent_puts( "{" );
   gen_backing_up();
   putchar( '\n' );
   }
  indent_puts( "++yy_cp;" );
  if ( num_backing_up > 0 )
   indent_puts( "}" );
  (--indent_level);
  putchar( '\n' );
  indent_puts( "yy_current_state = -yy_current_state;" );
  }
 else if ( fullspd )
  {
  indent_puts( "{" );
  indent_puts(
  "register const struct yy_trans_info *yy_trans_info;\n" );
  indent_puts( "register YY_CHAR yy_c;\n" );
  indent_put2s( "for ( yy_c = %s;", char_map );
  indent_puts(
 "      (yy_trans_info = &yy_current_state[(unsigned int) yy_c])->" );
  indent_puts( "yy_verify == yy_c;" );
  indent_put2s( "      yy_c = %s )", char_map_2 );
  (++indent_level);
  if ( num_backing_up > 0 )
   indent_puts( "{" );
  indent_puts( "yy_current_state += yy_trans_info->yy_nxt;" );
  if ( num_backing_up > 0 )
   {
   putchar( '\n' );
   gen_backing_up();
   indent_puts( "}" );
   }
  (--indent_level);
  indent_puts( "}" );
  }
 else
  {
  indent_puts( "do" );
  (++indent_level);
  indent_puts( "{" );
  gen_next_state( 0 );
  indent_puts( "++yy_cp;" );
  indent_puts( "}" );
  (--indent_level);
  do_indent();
  if ( interactive )
   printf( "while ( yy_base[yy_current_state] != %d );\n",
    jambase );
  else
   printf( "while ( yy_current_state != %d );\n",
    jamstate );
  if ( ! reject && ! interactive )
   {
   indent_puts( "yy_cp = yy_last_accepting_cpos;" );
   indent_puts(
    "yy_current_state = yy_last_accepting_state;" );
   }
  }
 }
void gen_next_state( worry_about_NULs )
int worry_about_NULs;
 {
 char char_map[256];
 if ( worry_about_NULs && ! nultrans )
  {
  if ( useecs )
   (void) sprintf( char_map,
    "(*yy_cp ? yy_ec[YY_SC_TO_UI(*yy_cp)] : %d)",
     NUL_ec );
  else
   (void) sprintf( char_map,
    "(*yy_cp ? YY_SC_TO_UI(*yy_cp) : %d)", NUL_ec );
  }
 else
  strcpy( char_map, useecs ? "yy_ec[YY_SC_TO_UI(*yy_cp)]" :
        "YY_SC_TO_UI(*yy_cp)" );
 if ( worry_about_NULs && nultrans )
  {
  if ( ! fulltbl && ! fullspd )
   gen_backing_up();
  indent_puts( "if ( *yy_cp )" );
  (++indent_level);
  indent_puts( "{" );
  }
 if ( fulltbl )
  indent_put2s(
   "yy_current_state = yy_nxt[yy_current_state][%s];",
    char_map );
 else if ( fullspd )
  indent_put2s(
   "yy_current_state += yy_current_state[%s].yy_nxt;",
    char_map );
 else
  gen_next_compressed_state( char_map );
 if ( worry_about_NULs && nultrans )
  {
  indent_puts( "}" );
  (--indent_level);
  indent_puts( "else" );
  (++indent_level);
  indent_puts(
   "yy_current_state = yy_NUL_trans[yy_current_state];" );
  (--indent_level);
  }
 if ( fullspd || fulltbl )
  gen_backing_up();
 if ( reject )
  indent_puts( "*yy_state_ptr++ = yy_current_state;" );
 }
void gen_NUL_trans()
 {
 int need_backing_up = (num_backing_up > 0 && ! reject);
 if ( need_backing_up )
  indent_puts( "register char *yy_cp = yy_c_buf_p;" );
 putchar( '\n' );
 if ( nultrans )
  {
  indent_puts(
   "yy_current_state = yy_NUL_trans[yy_current_state];" );
  indent_puts( "yy_is_jam = (yy_current_state == 0);" );
  }
 else if ( fulltbl )
  {
  do_indent();
  printf( "yy_current_state = yy_nxt[yy_current_state][%d];\n",
   NUL_ec );
  indent_puts( "yy_is_jam = (yy_current_state <= 0);" );
  }
 else if ( fullspd )
  {
  do_indent();
  printf( "register int yy_c = %d;\n", NUL_ec );
  indent_puts(
  "register const struct yy_trans_info *yy_trans_info;\n" );
  indent_puts(
  "yy_trans_info = &yy_current_state[(unsigned int) yy_c];" );
  indent_puts( "yy_current_state += yy_trans_info->yy_nxt;" );
  indent_puts(
   "yy_is_jam = (yy_trans_info->yy_verify != yy_c);" );
  }
 else
  {
  char NUL_ec_str[20];
  (void) sprintf( NUL_ec_str, "%d", NUL_ec );
  gen_next_compressed_state( NUL_ec_str );
  if ( reject )
   indent_puts( "*yy_state_ptr++ = yy_current_state;" );
  do_indent();
  printf( "yy_is_jam = (yy_current_state == %d);\n", jamstate );
  }
 if ( need_backing_up && (fullspd || fulltbl) )
  {
  putchar( '\n' );
  indent_puts( "if ( ! yy_is_jam )" );
  (++indent_level);
  indent_puts( "{" );
  gen_backing_up();
  indent_puts( "}" );
  (--indent_level);
  }
 }
void gen_start_state()
 {
 if ( fullspd )
  indent_put2s(
   "yy_current_state = yy_start_state_list[yy_start%s];",
   bol_needed ? " + (yy_bp[-1] == '\\n' ? 1 : 0)" : "" );
 else
  {
  indent_puts( "yy_current_state = yy_start;" );
  if ( bol_needed )
   {
   indent_puts( "if ( yy_bp[-1] == '\\n' )" );
   (++indent_level);
   indent_puts( "++yy_current_state;" );
   (--indent_level);
   }
  if ( reject )
   {
   indent_puts( "yy_state_ptr = yy_state_buf;" );
   indent_puts( "*yy_state_ptr++ = yy_current_state;" );
   }
  }
 }
void gentabs()
 {
 int i, j, k, *accset, nacc, *acc_array, total_states;
 int end_of_buffer_action = num_rules + 1;
 static char C_char_decl[] =
  "static const YY_CHAR %s[%d] =\n    {   0,\n";
 acc_array = (int *) allocate_array( current_max_dfas, sizeof( int ) );
 nummt = 0;
 ++num_backing_up;
 if ( reject )
  {
  int EOB_accepting_list[2];
  EOB_accepting_list[0] = 0;
  EOB_accepting_list[1] = end_of_buffer_action;
  accsiz[end_of_buffer_state] = 1;
  dfaacc[end_of_buffer_state].dfaacc_set = EOB_accepting_list;
  printf( long_align ? C_long_decl : C_short_decl,
   "yy_acclist", ((numas) > (1) ? (numas) : (1)) + 1 );
  j = 1;
  for ( i = 1; i <= lastdfa; ++i )
   {
   acc_array[i] = j;
   if ( accsiz[i] != 0 )
    {
    accset = dfaacc[i].dfaacc_set;
    nacc = accsiz[i];
    if ( trace )
     fprintf( err,
      "state # %d accepts: ", i );
    for ( k = 1; k <= nacc; ++k )
     {
     int accnum = accset[k];
     ++j;
     if ( variable_trailing_context_rules &&
       ! (accnum & 0x4000) &&
        accnum > 0 && accnum <= num_rules &&
       rule_type[accnum] == 1 )
      {
      accnum |= 0x2000;
      }
     mkdata( accnum );
     if ( trace )
      {
      fprintf( err, "[%d]",
       accset[k] );
      if ( k < nacc )
       fputs( ", ", err );
      else
       _IO_putc ('\n', err);
      }
     }
    }
   }
  acc_array[i] = j;
  dataend();
  }
 else
  {
  dfaacc[end_of_buffer_state].dfaacc_state = end_of_buffer_action;
  for ( i = 1; i <= lastdfa; ++i )
   acc_array[i] = dfaacc[i].dfaacc_state;
  acc_array[i] = 0;
  }
 k = lastdfa + 2;
 if ( reject )
  ++k;
 printf( long_align ? C_long_decl : C_short_decl, "yy_accept", k );
 for ( i = 1; i <= lastdfa; ++i )
  {
  mkdata( acc_array[i] );
  if ( ! reject && trace && acc_array[i] )
   fprintf( err, "state # %d accepts: [%d]\n",
    i, acc_array[i] );
  }
 mkdata( acc_array[i] );
 if ( reject )
  mkdata( acc_array[i] );
 dataend();
 if ( useecs )
  genecs();
 if ( usemecs )
  {
  if ( trace )
   fputs( "\n\nMeta-Equivalence Classes:\n", err );
  printf( C_int_decl, "yy_meta", numecs + 1 );
  for ( i = 1; i <= numecs; ++i )
   {
   if ( trace )
    fprintf( err, "%d = %d\n",
     i, ((tecbck[i]) < 0 ? -(tecbck[i]) : (tecbck[i])) );
   mkdata( ((tecbck[i]) < 0 ? -(tecbck[i]) : (tecbck[i])) );
   }
  dataend();
  }
 total_states = lastdfa + numtemps;
 printf( (tblend >= 32700 || long_align) ?
   C_long_decl : C_short_decl,
  "yy_base", total_states + 1 );
 for ( i = 1; i <= lastdfa; ++i )
  {
  register int d = def[i];
  if ( base[i] == -32766 )
   base[i] = jambase;
  if ( d == -32766 )
   def[i] = jamstate;
  else if ( d < 0 )
   {
   ++tmpuses;
   def[i] = lastdfa - d + 1;
   }
  mkdata( base[i] );
  }
 mkdata( base[i] );
 for ( ++i ; i <= total_states; ++i )
  {
  mkdata( base[i] );
  def[i] = jamstate;
  }
 dataend();
 printf( (total_states >= 32700 || long_align) ?
   C_long_decl : C_short_decl,
  "yy_def", total_states + 1 );
 for ( i = 1; i <= total_states; ++i )
  mkdata( def[i] );
 dataend();
 printf( (total_states >= 32700 || long_align) ?
   C_long_decl : C_short_decl,
  "yy_nxt", tblend + 1 );
 for ( i = 1; i <= tblend; ++i )
  {
  if ( nxt[i] == 0 || chk[i] == 0 )
   nxt[i] = jamstate;
  mkdata( nxt[i] );
  }
 dataend();
 printf( (total_states >= 32700 || long_align) ?
   C_long_decl : C_short_decl,
  "yy_chk", tblend + 1 );
 for ( i = 1; i <= tblend; ++i )
  {
  if ( chk[i] == 0 )
   ++nummt;
  mkdata( chk[i] );
  }
 dataend();
 }
void indent_put2s( fmt, arg )
char fmt[], arg[];
 {
 do_indent();
 printf( fmt, arg );
 putchar( '\n' );
 }
void indent_puts( str )
char str[];
 {
 do_indent();
 puts( str );
 }
void make_tables()
 {
 register int i;
 int did_eof_rule = 0;
 skelout();
 indent_level = 1;
 if ( yymore_used )
  {
  indent_puts( "yytext_ptr -= yy_more_len; \\" );
  indent_puts( "yyleng = yy_cp - yytext_ptr; \\" );
  }
 else
  indent_puts( "yyleng = yy_cp - yy_bp; \\" );
 skelout();
 if ( yytext_is_array )
  {
  indent_puts( "if ( yyleng >= YYLMAX ) \\" );
  (++indent_level);
  indent_puts(
  "YY_FATAL_ERROR( \"token too large, exceeds YYLMAX\" ); \\" );
  (--indent_level);
  indent_puts(
  "yy_flex_strncpy( yytext, yytext_ptr, yyleng + 1 ); \\" );
  }
 indent_level = 0;
 skelout();
 printf( "#define YY_END_OF_BUFFER %d\n", num_rules + 1 );
 if ( fullspd )
  {
  int total_table_size = tblend + numecs + 1;
  char *trans_offset_type =
   (total_table_size >= 32700 || long_align) ?
    "long" : "short";
  indent_level = 0;
  indent_puts( "struct yy_trans_info" );
  (++indent_level);
  indent_puts( "{" );
  if ( long_align )
   indent_puts( "long yy_verify;" );
  else
   indent_puts( "short yy_verify;" );
  indent_put2s( "%s yy_nxt;", trans_offset_type );
  indent_puts( "};" );
  (--indent_level);
  }
 if ( fullspd )
  genctbl();
 else if ( fulltbl )
  genftbl();
 else
  gentabs();
 if ( num_backing_up > 0 && ! reject )
  {
  if ( ! C_plus_plus )
   {
   indent_puts(
   "static yy_state_type yy_last_accepting_state;" );
   indent_puts(
    "static char *yy_last_accepting_cpos;\n" );
   }
  }
 if ( nultrans )
  {
  printf( C_state_decl, "yy_NUL_trans", lastdfa + 1 );
  for ( i = 1; i <= lastdfa; ++i )
   {
   if ( fullspd )
    printf( "    &yy_transition[%d],\n", base[i] );
   else
    mkdata( nultrans[i] );
   }
  dataend();
  }
 if ( ddebug )
  {
  indent_puts( "extern int yy_flex_debug;" );
  indent_puts( "int yy_flex_debug = 1;\n" );
  printf( long_align ? C_long_decl : C_short_decl,
   "yy_rule_linenum", num_rules );
  for ( i = 1; i < num_rules; ++i )
   mkdata( rule_linenum[i] );
  dataend();
  }
 if ( reject )
  {
  if ( ! C_plus_plus )
   {
   puts(
 "static yy_state_type yy_state_buf[YY_BUF_SIZE + 2], *yy_state_ptr;" );
   puts( "static char *yy_full_match;" );
   puts( "static int yy_lp;" );
   }
  if ( variable_trailing_context_rules )
   {
   if ( ! C_plus_plus )
    {
    puts(
    "static int yy_looking_for_trail_begin = 0;" );
    puts( "static int yy_full_lp;" );
    puts( "static int *yy_full_state;" );
    }
   printf( "#define YY_TRAILING_MASK 0x%x\n",
    (unsigned int) 0x2000 );
   printf( "#define YY_TRAILING_HEAD_MASK 0x%x\n",
    (unsigned int) 0x4000 );
   }
  puts( "#define REJECT \\" );
  puts( "{ \\" );
  puts(
 "*yy_cp = yy_hold_char; /* undo effects of setting up yytext */ \\" );
  puts(
 "yy_cp = yy_full_match; /* restore poss. backed-over text */ \\" );
  if ( variable_trailing_context_rules )
   {
   puts(
  "yy_lp = yy_full_lp; /* restore orig. accepting pos. */ \\" );
   puts(
  "yy_state_ptr = yy_full_state; /* restore orig. state */ \\" );
   puts(
 "yy_current_state = *yy_state_ptr; /* restore curr. state */ \\" );
   }
  puts( "++yy_lp; \\" );
  puts( "goto find_rule; \\" );
  puts( "}" );
  }
 else
  {
  puts(
  "/* The intent behind this definition is that it'll catch" );
  puts( " * any uses of REJECT which flex missed." );
  puts( " */" );
  puts( "#define REJECT reject_used_but_not_detected" );
  }
 if ( yymore_used )
  {
  if ( ! C_plus_plus )
   {
   indent_puts( "static int yy_more_flag = 0;" );
   indent_puts( "static int yy_more_len = 0;" );
   }
  indent_puts( "#define yymore() (yy_more_flag = 1)" );
  indent_puts( "#define YY_MORE_ADJ yy_more_len" );
  }
 else
  {
  indent_puts( "#define yymore() yymore_used_but_not_detected" );
  indent_puts( "#define YY_MORE_ADJ 0" );
  }
 if ( ! C_plus_plus )
  {
  if ( yytext_is_array )
   {
   puts( "#ifndef YYLMAX" );
   puts( "#define YYLMAX 8192" );
   puts( "#endif\n" );
   puts( "char yytext[YYLMAX];" );
   puts( "char *yytext_ptr;" );
   }
  else
   puts( "char *yytext;" );
  }
 fputs( &action_array[defs1_offset], stdout );
 skelout();
 if ( ! C_plus_plus )
  {
  if ( use_read )
   {
   printf(
"\tif ( (result = read( fileno(yyin), (char *) buf, max_size )) < 0 ) \\\n" );
   printf(
  "\t\tYY_FATAL_ERROR( \"input in flex scanner failed\" );\n" );
   }
  else
   {
   printf(
   "\tif ( yy_current_buffer->yy_is_interactive ) \\\n" );
   printf( "\t\t{ \\\n" );
   printf( "\t\tint c = getc( yyin ); \\\n" );
   printf( "\t\tresult = c == EOF ? 0 : 1; \\\n" );
   printf( "\t\tbuf[0] = (char) c; \\\n" );
   printf( "\t\t} \\\n" );
            printf(
 "\telse if ( ((result = fread( buf, 1, max_size, yyin )) == 0) \\\n" );
   printf( "\t\t  && ferror( yyin ) ) \\\n" );
   printf(
  "\t\tYY_FATAL_ERROR( \"input in flex scanner failed\" );\n" );
   }
  }
 skelout();
 fputs( &action_array[prolog_offset], stdout );
 skelout();
 indent_level = 2;
 if ( yymore_used )
  {
  indent_puts( "yy_more_len = 0;" );
  indent_puts( "if ( yy_more_flag )" );
  (++indent_level);
  indent_puts( "{" );
  indent_puts( "yy_more_len = yyleng;" );
  indent_puts( "yy_more_flag = 0;" );
  indent_puts( "}" );
  (--indent_level);
  }
 skelout();
 gen_start_state();
 puts( "yy_match:" );
 gen_next_match();
 skelout();
 indent_level = 2;
 gen_find_action();
 skelout();
 if ( lex_compat )
  {
  indent_puts( "if ( yy_act != YY_END_OF_BUFFER )" );
  (++indent_level);
  indent_puts( "{" );
  indent_puts( "int yyl;" );
  indent_puts( "for ( yyl = 0; yyl < yyleng; ++yyl )" );
  (++indent_level);
  indent_puts( "if ( yytext[yyl] == '\\n' )" );
  (++indent_level);
  indent_puts( "++yylineno;" );
  (--indent_level);
  (--indent_level);
  indent_puts( "}" );
  (--indent_level);
  }
 skelout();
 if ( ddebug )
  {
  indent_puts( "if ( yy_flex_debug )" );
  (++indent_level);
  indent_puts( "{" );
  indent_puts( "if ( yy_act == 0 )" );
  (++indent_level);
  indent_puts(
   "fprintf( stderr, \"--scanner backing up\\n\" );" );
  (--indent_level);
  do_indent();
  printf( "else if ( yy_act < %d )\n", num_rules );
  (++indent_level);
  indent_puts(
 "fprintf( stderr, \"--accepting rule at line %d (\\\"%s\\\")\\n\"," );
  indent_puts( "         yy_rule_linenum[yy_act], yytext );" );
  (--indent_level);
  do_indent();
  printf( "else if ( yy_act == %d )\n", num_rules );
  (++indent_level);
  indent_puts(
 "fprintf( stderr, \"--accepting default rule (\\\"%s\\\")\\n\"," );
  indent_puts( "         yytext );" );
  (--indent_level);
  do_indent();
  printf( "else if ( yy_act == %d )\n", num_rules + 1 );
  (++indent_level);
  indent_puts(
 "fprintf( stderr, \"--(end of buffer or a NUL)\\n\" );" );
  (--indent_level);
  do_indent();
  printf( "else\n" );
  (++indent_level);
  indent_puts(
 "fprintf( stderr, \"--EOF (start condition %d)\\n\", YY_START );" );
  (--indent_level);
  indent_puts( "}" );
  (--indent_level);
  }
 skelout();
 (++indent_level);
 gen_bu_action();
 fputs( &action_array[action_offset], stdout );
 for ( i = 1; i <= lastsc; ++i )
  if ( ! sceof[i] )
   {
   do_indent();
   printf( "case YY_STATE_EOF(%s):\n", scname[i] );
   did_eof_rule = 1;
   }
 if ( did_eof_rule )
  {
  (++indent_level);
  indent_puts( "yyterminate();" );
  (--indent_level);
  }
 skelout();
 indent_level = 7;
 if ( fullspd || fulltbl )
  indent_puts( "yy_cp = yy_c_buf_p;" );
 else
  {
  if ( ! reject && ! interactive )
   {
   indent_puts( "yy_cp = yy_last_accepting_cpos;" );
   indent_puts(
    "yy_current_state = yy_last_accepting_state;" );
   }
  else
   indent_puts( "yy_cp = yy_c_buf_p;" );
  }
 indent_level = 1;
 skelout();
 if ( bol_needed )
  indent_puts( "register char *yy_bp = yytext_ptr;\n" );
 gen_start_state();
 indent_level = 2;
 skelout();
 gen_next_state( 1 );
 indent_level = 1;
 skelout();
 gen_NUL_trans();
 skelout();
 if ( lex_compat )
  {
  indent_puts( "if ( c == '\\n' )" );
  (++indent_level);
  indent_puts( "--yylineno;" );
  (--indent_level);
  }
 skelout();
 line_directive_out( stdout );
 if ( sectnum == 3 )
  (void) flexscan();
 }
void dataflush (void);
int otoi (unsigned char []);
void add_action( new_text )
char *new_text;
 {
 int len = strlen( new_text );
 while ( len + action_index >= action_size - 10 )
  {
  action_size *= 2;
  action_array =
   (char *) reallocate_array( (void *) action_array, action_size, sizeof( char ) );
  }
 strcpy( &action_array[action_index], new_text );
 action_index += len;
 }
void *allocate_array( size, element_size )
int size, element_size;
 {
 register void *mem;
 if ( element_size * size <= 0 )
  flexfatal( "request for < 1 byte in allocate_array()" );
 mem = flex_alloc( element_size * size);
    "";
 if ( mem == ((void *)0) )
  flexfatal( "memory allocation failed in allocate_array()" );
 return mem;
 }
int all_lower( str )
register char *str;
 {
 while ( *str )
  {
  if ( ! ((((unsigned char) *str) & ~0x7f) == 0) || ! ((*__ctype_b_loc ())[(int) ((*str))] & (unsigned short int) _ISlower) )
   return 0;
  ++str;
  }
 return 1;
 }
int all_upper( str )
register char *str;
 {
 while ( *str )
  {
  if ( ! ((((unsigned char) *str) & ~0x7f) == 0) || ! ((*__ctype_b_loc ())[(int) ((*str))] & (unsigned short int) _ISupper) )
   return 0;
  ++str;
  }
 return 1;
 }
void bubble( v, n )
int v[], n;
 {
 register int i, j, k;
 for ( i = n; i > 1; --i )
  for ( j = 1; j < i; ++j )
   if ( v[j] > v[j + 1] )
    {
    k = v[j];
    v[j] = v[j + 1];
    v[j + 1] = k;
    }
 }
void check_char( c )
int c;
 {
 if ( c >= 256 )
  lerrsf( "bad character '%s' detected in check_char()",
   readable_form( c ) );
 if ( c >= csize )
  lerrsf( "scanner requires -8 flag to use the character '%s'",
   readable_form( c ) );
 }
unsigned char clower( c )
register int c;
 {
 return (unsigned char) (((((c) & ~0x7f) == 0) && ((*__ctype_b_loc ())[(int) ((c))] & (unsigned short int) _ISupper)) ? tolower( c ) : c);
 }
char *copy_string( str )
register char *str;
 {
 register char *c;
 char *copy;
 for ( c = str; *c; ++c )
  ;
 copy = (char *) flex_alloc( (c - str + 1) * sizeof( char ) );
 if ( copy == ((void *)0) )
  flexfatal( "dynamic memory failure in copy_string()" );
 for ( c = copy; (*c++ = *str++); )
  ;
 return copy;
 }
unsigned char *copy_unsigned_string( str )
register unsigned char *str;
 {
 register unsigned char *c;
 unsigned char *copy;
 for ( c = str; *c; ++c )
  ;
 copy = (unsigned char *) allocate_array( c - str + 1, sizeof( unsigned char ) );
 for ( c = copy; (*c++ = *str++); )
  ;
 return copy;
 }
void cshell( v, n, special_case_0 )
unsigned char v[];
int n, special_case_0;
 {
 int gap, i, j, jg;
 unsigned char k;
 for ( gap = n / 2; gap > 0; gap = gap / 2 )
  for ( i = gap; i < n; ++i )
   for ( j = i - gap; j >= 0; j = j - gap )
    {
    jg = j + gap;
    if ( special_case_0 )
     {
     if ( v[jg] == 0 )
      break;
     else if ( v[j] != 0 && v[j] <= v[jg] )
      break;
     }
    else if ( v[j] <= v[jg] )
     break;
    k = v[j];
    v[j] = v[jg];
    v[jg] = k;
    }
 }
void dataend()
 {
 if ( datapos > 0 )
  dataflush();
 puts( "    } ;\n" );
 dataline = 0;
 datapos = 0;
 }
void dataflush()
 {
 putchar( '\n' );
 if ( ++dataline >= 10 )
  {
  putchar( '\n' );
  dataline = 0;
  }
 datapos = 0;
 }
void flexerror( msg )
char msg[];
 {
 fprintf( err, "%s: %s\n", program_name, msg );
 flexend( 1 );
 }
void flexfatal( msg )
char msg[];
 {
 fprintf( err, "%s: fatal internal error, %s\n", program_name, msg );
 exit( 1 );
 }
void lerrif( msg, arg )
char msg[];
int arg;
 {
 char errmsg[2048];
 (void) sprintf( errmsg, msg, arg );
 flexerror( errmsg );
 }
void lerrsf( msg, arg )
char msg[], arg[];
 {
 char errmsg[2048];
 (void) sprintf( errmsg, msg, arg );
 flexerror( errmsg );
 }
int htoi( str )
unsigned char str[];
 {
 unsigned int result;
 (void) sscanf( (char *) str, "%x", &result );
 return result;
 }
int is_hex_digit( ch )
int ch;
 {
 if ( ((*__ctype_b_loc ())[(int) ((ch))] & (unsigned short int) _ISdigit) )
  return 1;
 switch ( clower( ch ) )
  {
  case 'a':
  case 'b':
  case 'c':
  case 'd':
  case 'e':
  case 'f':
   return 1;
  default:
   return 0;
  }
 }
void line_directive_out( output_file )
FILE *output_file;
 {
 if ( infilename && gen_line_dirs )
  {
  char directive[2048];
  sprintf( directive, "# line %d \"%s\"\n", linenum, infilename );
  if ( output_file )
   fputs( directive, output_file );
  else
   add_action( directive );
  }
 }
void mark_defs1()
 {
 defs1_offset = 0;
 action_array[action_index++] = '\0';
 action_offset = prolog_offset = action_index;
 action_array[action_index] = '\0';
 }
void mark_prolog()
 {
 action_array[action_index++] = '\0';
 action_offset = action_index;
 action_array[action_index] = '\0';
 }
void mk2data( value )
int value;
 {
 if ( datapos >= 10 )
  {
  putchar( ',' );
  dataflush();
  }
 if ( datapos == 0 )
  fputs( "    ", stdout );
 else
  putchar( ',' );
 ++datapos;
 printf( "%5d", value );
 }
void mkdata( value )
int value;
 {
 if ( datapos >= 10 )
  {
  putchar( ',' );
  dataflush();
  }
 if ( datapos == 0 )
  fputs( "    ", stdout );
 else
  putchar( ',' );
 ++datapos;
 printf( "%5d", value );
 }
int myctoi( array )
char array[];
 {
 int val = 0;
 (void) sscanf( array, "%d", &val );
 return val;
 }
unsigned char myesc( array )
unsigned char array[];
 {
 unsigned char c, esc_char;
 switch ( array[1] )
  {
  case 'b': return '\b';
  case 'f': return '\f';
  case 'n': return '\n';
  case 'r': return '\r';
  case 't': return '\t';
  case 'a': return '\a';
  case 'v': return '\v';
  case '0':
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9':
   {
   int sptr = 1;
   while ( (((array[sptr]) & ~0x7f) == 0) &&
    ((*__ctype_b_loc ())[(int) ((array[sptr]))] & (unsigned short int) _ISdigit) )
    ++sptr;
   c = array[sptr];
   array[sptr] = '\0';
   esc_char = otoi( array + 1 );
   array[sptr] = c;
   return esc_char;
   }
  case 'x':
   {
   int sptr = 2;
   while ( (((array[sptr]) & ~0x7f) == 0) &&
    is_hex_digit( (char) array[sptr] ) )
    ++sptr;
   c = array[sptr];
   array[sptr] = '\0';
   esc_char = htoi( array + 2 );
   array[sptr] = c;
   return esc_char;
   }
  default:
   return array[1];
  }
 }
int otoi( str )
unsigned char str[];
 {
 unsigned int result;
 (void) sscanf( (char *) str, "%o", &result );
 return result;
 }
char *readable_form( c )
register int c;
 {
 static char rform[10];
 if ( (c >= 0 && c < 32) || c >= 127 )
  {
  switch ( c )
   {
   case '\b': return "\\b";
   case '\f': return "\\f";
   case '\n': return "\\n";
   case '\r': return "\\r";
   case '\t': return "\\t";
   case '\a': return "\\a";
   case '\v': return "\\v";
   default:
    (void) sprintf( rform, "\\%.3o",
      (unsigned int) c );
    return rform;
   }
  }
 else if ( c == ' ' )
  return "' '";
 else
  {
  rform[0] = c;
  rform[1] = '\0';
  return rform;
  }
 }
void *reallocate_array( array, size, element_size )
void *array;
int size, element_size;
 {
 register void *new_array;
 if ( size * element_size <= 0 )
  flexfatal(
   "attempt to increase array size by less than 1 byte" );
 new_array = flex_realloc( array, size * element_size );
 if ( new_array == ((void *)0) )
  flexfatal( "attempt to increase array size failed" );
 return new_array;
 }
void skelout()
 {
 char buf_storage[2048];
 char *buf = buf_storage;
 int do_copy = 1;
 while ( skelfile ?
  (fgets( buf, 2048, skelfile ) != ((void *)0)) :
  ((buf = skel[skel_ind++]) != 0) )
  {
  if ( buf[0] == '%' )
   {
   switch ( buf[1] )
    {
    case '%':
     return;
    case '+':
     do_copy = C_plus_plus;
     break;
    case '-':
     do_copy = ! C_plus_plus;
     break;
    case '*':
     do_copy = 1;
     break;
    default:
     flexfatal(
      "bad line in skeleton file" );
    }
   }
  else if ( do_copy )
   {
   if ( skelfile )
    fputs( buf, stdout );
   else
    printf( "%s\n", buf );
   }
  }
 }
void transition_struct_out( element_v, element_n )
int element_v, element_n;
 {
 printf( "%7d, %5d,", element_v, element_n );
 datapos += 15;
 if ( datapos >= 75 )
  {
  putchar( '\n' );
  if ( ++dataline % 10 == 0 )
   putchar( '\n' );
  datapos = 0;
  }
 }
void *yy_flex_xmalloc( size )
int size;
 {
 void *result = flex_alloc( size );
 if ( ! result )
  flexfatal( "memory allocation failed in yy_flex_xmalloc()" );
 return result;
 }
void zero_out( region_ptr, size_in_bytes )
char *region_ptr;
int size_in_bytes;
 {
 register char *rp, *rp_end;
 rp = region_ptr;
 rp_end = region_ptr + size_in_bytes;
 while ( rp < rp_end )
  *rp++ = 0;
 }
int dupmachine (int);
void mkxtion (int, int);
void add_accept( mach, accepting_number )
int mach, accepting_number;
 {
 if ( transchar[finalst[mach]] == (256 + 1) )
  accptnum[finalst[mach]] = accepting_number;
 else
  {
  int astate = mkstate( (256 + 1) );
  accptnum[astate] = accepting_number;
  (void) link_machines( mach, astate );
  }
 }
int copysingl( singl, num )
int singl, num;
 {
 int copy, i;
 copy = mkstate( (256 + 1) );
 for ( i = 1; i <= num; ++i )
  copy = link_machines( copy, dupmachine( singl ) );
 return copy;
 }
void dumpnfa( state1 )
int state1;
 {
 int sym, tsp1, tsp2, anum, ns;
 fprintf( err,
  "\n\n********** beginning dump of nfa with start state %d\n",
  state1 );
 for ( ns = 1; ns <= lastnfa; ++ns )
  {
  fprintf( err, "state # %4d\t", ns );
  sym = transchar[ns];
  tsp1 = trans1[ns];
  tsp2 = trans2[ns];
  anum = accptnum[ns];
  fprintf( err, "%3d:  %4d, %4d", sym, tsp1, tsp2 );
  if ( anum != 0 )
   fprintf( err, "  [%d]", anum );
  fprintf( err, "\n" );
  }
 fprintf( err, "********** end of dump\n" );
 }
int dupmachine( mach )
int mach;
 {
 int i, init, state_offset;
 int state = 0;
 int last = lastst[mach];
 for ( i = firstst[mach]; i <= last; ++i )
  {
  state = mkstate( transchar[i] );
  if ( trans1[i] != 0 )
   {
   mkxtion( finalst[state], trans1[i] + state - i );
   if ( transchar[i] == (256 + 1) &&
        trans2[i] != 0 )
    mkxtion( finalst[state],
     trans2[i] + state - i );
   }
  accptnum[state] = accptnum[i];
  }
 if ( state == 0 )
  flexfatal( "empty machine in dupmachine()" );
 state_offset = state - i + 1;
 init = mach + state_offset;
 firstst[init] = firstst[mach] + state_offset;
 finalst[init] = finalst[mach] + state_offset;
 lastst[init] = lastst[mach] + state_offset;
 return init;
 }
void finish_rule( mach, variable_trail_rule, headcnt, trailcnt )
int mach, variable_trail_rule, headcnt, trailcnt;
 {
 char action_text[2048];
 add_accept( mach, num_rules );
 rule_linenum[num_rules] = linenum;
 if ( continued_action )
  --rule_linenum[num_rules];
 sprintf( action_text, "case %d:\n", num_rules );
 add_action( action_text );
 if ( variable_trail_rule )
  {
  rule_type[num_rules] = 1;
  if ( performance_report > 0 )
   fprintf( err,
    "Variable trailing context rule at line %d\n",
    rule_linenum[num_rules] );
  variable_trailing_context_rules = 1;
  }
 else
  {
  rule_type[num_rules] = 0;
  if ( headcnt > 0 || trailcnt > 0 )
   {
   char *scanner_cp = "yy_c_buf_p = yy_cp";
   char *scanner_bp = "yy_bp";
   add_action(
 "*yy_cp = yy_hold_char; /* undo effects of setting up yytext */\n" );
   if ( headcnt > 0 )
    {
    sprintf( action_text, "%s = %s + %d;\n",
    scanner_cp, scanner_bp, headcnt );
    add_action( action_text );
    }
   else
    {
    sprintf( action_text, "%s -= %d;\n",
     scanner_cp, trailcnt );
    add_action( action_text );
    }
   add_action(
   "YY_DO_BEFORE_ACTION; /* set up yytext again */\n" );
   }
  }
 if ( ! continued_action )
        add_action( "YY_USER_ACTION\n" );
 line_directive_out( (FILE *) 0 );
 }
int link_machines( first, last )
int first, last;
 {
 if ( first == 0 )
  return last;
 else if ( last == 0 )
  return first;
 else
  {
  mkxtion( finalst[first], last );
  finalst[first] = finalst[last];
  lastst[first] = ((lastst[first]) > (lastst[last]) ? (lastst[first]) : (lastst[last]));
  firstst[first] = ((firstst[first]) < (firstst[last]) ? (firstst[first]) : (firstst[last]));
  return first;
  }
 }
void mark_beginning_as_normal( mach )
register int mach;
 {
 switch ( state_type[mach] )
  {
  case 0x1:
   return;
  case 0x2:
   state_type[mach] = 0x1;
   if ( transchar[mach] == (256 + 1) )
    {
    if ( trans1[mach] != 0 )
     mark_beginning_as_normal(
      trans1[mach] );
    if ( trans2[mach] != 0 )
     mark_beginning_as_normal(
      trans2[mach] );
    }
   break;
  default:
   flexerror(
    "bad state type in mark_beginning_as_normal()" );
   break;
  }
 }
int mkbranch( first, second )
int first, second;
 {
 int eps;
 if ( first == 0 )
  return second;
 else if ( second == 0 )
  return first;
 eps = mkstate( (256 + 1) );
 mkxtion( eps, first );
 mkxtion( eps, second );
 return eps;
 }
int mkclos( state )
int state;
 {
 return mkopt( mkposcl( state ) );
 }
int mkopt( mach )
int mach;
 {
 int eps;
 if ( ! (transchar[finalst[mach]] == (256 + 1) && trans1[finalst[mach]] == 0) )
  {
  eps = mkstate( (256 + 1) );
  mach = link_machines( mach, eps );
  }
 eps = mkstate( (256 + 1) );
 mach = link_machines( eps, mach );
 mkxtion( mach, finalst[mach] );
 return mach;
 }
int mkor( first, second )
int first, second;
 {
 int eps, orend;
 if ( first == 0 )
  return second;
 else if ( second == 0 )
  return first;
 else
  {
  eps = mkstate( (256 + 1) );
  first = link_machines( eps, first );
  mkxtion( first, second );
  if ( (transchar[finalst[first]] == (256 + 1) && trans1[finalst[first]] == 0) &&
       accptnum[finalst[first]] == 0 )
   {
   orend = finalst[first];
   mkxtion( finalst[second], orend );
   }
  else if ( (transchar[finalst[second]] == (256 + 1) && trans1[finalst[second]] == 0) &&
     accptnum[finalst[second]] == 0 )
   {
   orend = finalst[second];
   mkxtion( finalst[first], orend );
   }
  else
   {
   eps = mkstate( (256 + 1) );
   first = link_machines( first, eps );
   orend = finalst[first];
   mkxtion( finalst[second], orend );
   }
  }
 finalst[first] = orend;
 return first;
 }
int mkposcl( state )
int state;
 {
 int eps;
 if ( (transchar[finalst[state]] == (256 + 1) && trans1[finalst[state]] == 0) )
  {
  mkxtion( finalst[state], state );
  return state;
  }
 else
  {
  eps = mkstate( (256 + 1) );
  mkxtion( eps, state );
  return link_machines( state, eps );
  }
 }
int mkrep( mach, lb, ub )
int mach, lb, ub;
 {
 int base_mach, tail, copy, i;
 base_mach = copysingl( mach, lb - 1 );
 if ( ub == -1 )
  {
  copy = dupmachine( mach );
  mach = link_machines( mach,
  link_machines( base_mach, mkclos( copy ) ) );
  }
 else
  {
  tail = mkstate( (256 + 1) );
  for ( i = lb; i < ub; ++i )
   {
   copy = dupmachine( mach );
   tail = mkopt( link_machines( copy, tail ) );
   }
  mach = link_machines( mach, link_machines( base_mach, tail ) );
  }
 return mach;
 }
int mkstate( sym )
int sym;
 {
 if ( ++lastnfa >= current_mns )
  {
  if ( (current_mns += 1000) >= 31999 )
   lerrif(
   "input rules are too complicated (>= %d NFA states)",
    current_mns );
  ++num_reallocs;
  firstst = (int *) reallocate_array( (void *) firstst, current_mns, sizeof( int ) );
  lastst = (int *) reallocate_array( (void *) lastst, current_mns, sizeof( int ) );
  finalst = (int *) reallocate_array( (void *) finalst, current_mns, sizeof( int ) );
  transchar = (int *) reallocate_array( (void *) transchar, current_mns, sizeof( int ) );
  trans1 = (int *) reallocate_array( (void *) trans1, current_mns, sizeof( int ) );
  trans2 = (int *) reallocate_array( (void *) trans2, current_mns, sizeof( int ) );
  accptnum = (int *) reallocate_array( (void *) accptnum, current_mns, sizeof( int ) );
  assoc_rule =
   (int *) reallocate_array( (void *) assoc_rule, current_mns, sizeof( int ) );
  state_type =
   (int *) reallocate_array( (void *) state_type, current_mns, sizeof( int ) );
  }
 firstst[lastnfa] = lastnfa;
 finalst[lastnfa] = lastnfa;
 lastst[lastnfa] = lastnfa;
 transchar[lastnfa] = sym;
 trans1[lastnfa] = 0;
 trans2[lastnfa] = 0;
 accptnum[lastnfa] = 0;
 assoc_rule[lastnfa] = num_rules;
 state_type[lastnfa] = current_state_type;
 if ( sym < 0 )
  {
  }
 else if ( sym == (256 + 1) )
  ++numeps;
 else
  {
  check_char( sym );
  if ( useecs )
   mkechar( sym ? sym : csize, nextecm, ecgroup );
  }
 return lastnfa;
 }
void mkxtion( statefrom, stateto )
int statefrom, stateto;
 {
 if ( trans1[statefrom] == 0 )
  trans1[statefrom] = stateto;
 else if ( (transchar[statefrom] != (256 + 1)) ||
    (trans2[statefrom] != 0) )
  flexfatal( "found too many transitions in mkxtion()" );
 else
  {
  ++eps2;
  trans2[statefrom] = stateto;
  }
 }
void new_rule()
 {
 if ( ++num_rules >= current_max_rules )
  {
  ++num_reallocs;
  current_max_rules += 100;
  rule_type = (int *) reallocate_array( (void *) rule_type, current_max_rules, sizeof( int ) );
  rule_linenum = (int *) reallocate_array( (void *) rule_linenum, current_max_rules, sizeof( int ) );
  rule_useful = (int *) reallocate_array( (void *) rule_useful, current_max_rules, sizeof( int ) );
  }
 if ( num_rules > (0x2000 - 1) )
  lerrif( "too many rules (> %d)!", (0x2000 - 1) );
 rule_linenum[num_rules] = linenum;
 rule_useful[num_rules] = 0;
 }
char *skel[] = {
  "/* A lexical scanner generated by flex */",
  "",
  "/* Scanner skeleton version:",
  " * $Header: /a1/cvsadm/cvsroot/expsir/csubjects/flex/versions.alt/versions.seeded/v1/flex.c,v 1.1.1.2 2003/09/02 20:21:59 expsir Exp $",
  " */",
  "",
  "#define FLEX_SCANNER",
  "",
  "%-",
  "#include <stdio.h>",
  "%*",
  "",
  "",
  "/* cfront 1.2 defines \"c_plusplus\" instead of \"__cplusplus\" */",
  "#ifdef c_plusplus",
  "#ifndef __cplusplus",
  "#define __cplusplus",
  "#endif",
  "#endif",
  "",
  "",
  "#ifdef __cplusplus",
  "",
  "#include <stdlib.h>",
  "%+",
  "class istream;",
  "%*",
  "#include <unistd.h>",
  "",
  "/* Use prototypes in function declarations. */",
  "#define YY_USE_PROTOS",
  "",
  "/* The \"const\" storage-class-modifier is valid. */",
  "#define YY_USE_CONST",
  "",
  "#else	/* ! __cplusplus */",
  "",
  "#ifdef __STDC__",
  "",
  "#define YY_USE_PROTOS",
  "#define YY_USE_CONST",
  "",
  "#endif	/* __STDC__ */",
  "#endif	/* ! __cplusplus */",
  "",
  "",
  "#ifdef __TURBOC__",
  "#define YY_USE_CONST",
  "#endif",
  "",
  "",
  "#ifndef YY_USE_CONST",
  "#ifndef const",
  "#define const",
  "#endif",
  "#endif",
  "",
  "",
  "#ifdef YY_USE_PROTOS",
  "#define YY_PROTO(proto) proto",
  "#else",
  "#define YY_PROTO(proto) ()",
  "#endif",
  "",
  "/* Returned upon end-of-file. */",
  "#define YY_NULL 0",
  "",
  "/* Promotes a possibly negative, possibly signed char to an unsigned",
  " * integer for use as an array index.  If the signed char is negative,",
  " * we want to instead treat it as an 8-bit unsigned char, hence the",
  " * double cast.",
  " */",
  "#define YY_SC_TO_UI(c) ((unsigned int) (unsigned char) c)",
  "",
  "/* Enter a start condition.  This macro really ought to take a parameter,",
  " * but we do it the disgusting crufty way forced on us by the ()-less",
  " * definition of BEGIN.",
  " */",
  "#define BEGIN yy_start = 1 + 2 *",
  "",
  "/* Translate the current start state into a value that can be later handed",
  " * to BEGIN to return to the state.",
  " */",
  "#define YY_START ((yy_start - 1) / 2)",
  "",
  "/* Action number for EOF rule of a given start state. */",
  "#define YY_STATE_EOF(state) (YY_END_OF_BUFFER + state + 1)",
  "",
  "/* Special action meaning \"start processing a new file\".  Now included",
  " * only for backward compatibility with previous versions of flex.",
  " */",
  "#define YY_NEW_FILE yyrestart( yyin )",
  "",
  "#define YY_END_OF_BUFFER_CHAR 0",
  "",
  "/* Size of default input buffer. */",
  "#define YY_BUF_SIZE 16384",
  "",
  "typedef struct yy_buffer_state *YY_BUFFER_STATE;",
  "",
  "extern int yyleng;",
  "%-",
  "extern FILE *yyin, *yyout;",
  "%*",
  "",
  "#ifdef __cplusplus",
  "extern \"C\" {",
  "#endif",
  "	extern int yywrap YY_PROTO(( void ));",
  "#ifdef __cplusplus",
  "	}",
  "#endif",
  "",
  "#define EOB_ACT_CONTINUE_SCAN 0",
  "#define EOB_ACT_END_OF_FILE 1",
  "#define EOB_ACT_LAST_MATCH 2",
  "",
  "/* The funky do-while in the following #define is used to turn the definition",
  " * int a single C statement (which needs a semi-colon terminator).  This",
  " * avoids problems with code like:",
  " *",
  " * 	if ( condition_holds )",
  " *		yyless( 5 );",
  " *	else",
  " *		do_something_else();",
  " *",
  " * Prior to using the do-while the compiler would get upset at the",
  " * \"else\" because it interpreted the \"if\" statement as being all",
  " * done when it reached the ';' after the yyless() call.",
  " */",
  "",
  "/* Return all but the first 'n' matched characters back to the input stream. */",
  "",
  "#define yyless(n) \\",
  "	do \\",
  "		{ \\",
  "		/* Undo effects of setting up yytext. */ \\",
  "		*yy_cp = yy_hold_char; \\",
  "		yy_c_buf_p = yy_cp = yy_bp + n - YY_MORE_ADJ; \\",
  "		YY_DO_BEFORE_ACTION; /* set up yytext again */ \\",
  "		} \\",
  "	while ( 0 )",
  "",
  "#define unput(c) yyunput( c, yytext_ptr )",
  "",
  "",
  "struct yy_buffer_state",
  "	{",
  "%-",
  "	FILE *yy_input_file;",
  "%+",
  "	istream* yy_input_file;",
  "%*",
  "",
  "	char *yy_ch_buf;		/* input buffer */",
  "	char *yy_buf_pos;		/* current position in input buffer */",
  "",
  "	/* Size of input buffer in bytes, not including room for EOB",
  "	 * characters.",
  "	 */",
  "	int yy_buf_size;",
  "",
  "	/* Number of characters read into yy_ch_buf, not including EOB",
  "	 * characters.",
  "	 */",
  "	int yy_n_chars;",
  "",
  "	/* Whether this is an \"interactive\" input source; if so, and",
  "	 * if we're using stdio for input, then we want to use getc()",
  "	 * instead of fread(), to make sure we stop fetching input after",
  "	 * each newline.",
  "	 */",
  "	int yy_is_interactive;",
  "",
  "	/* Whether to try to fill the input buffer when we reach the",
  "	 * end of it.",
  "	 */",
  "	int yy_fill_buffer;",
  "",
  "	int yy_buffer_status;",
  "#define YY_BUFFER_NEW 0",
  "#define YY_BUFFER_NORMAL 1",
  "	/* When an EOF's been seen but there's still some text to process",
  "	 * then we mark the buffer as YY_EOF_PENDING, to indicate that we",
  "	 * shouldn't try reading from the input source any more.  We might",
  "	 * still have a bunch of tokens to match, though, because of",
  "	 * possible backing-up.",
  "	 *",
  "	 * When we actually see the EOF, we change the status to \"new\"",
  "	 * (via yyrestart()), so that the user can continue scanning by",
  "	 * just pointing yyin at a new input file.",
  "	 */",
  "#define YY_BUFFER_EOF_PENDING 2",
  "	};",
  "",
  "%- Standard (non-C++) definition",
  "static YY_BUFFER_STATE yy_current_buffer = 0;",
  "%*",
  "",
  "/* We provide macros for accessing buffer states in case in the",
  " * future we want to put the buffer states in a more general",
  " * \"scanner state\".",
  " */",
  "#define YY_CURRENT_BUFFER yy_current_buffer",
  "",
  "",
  "%- Standard (non-C++) definition",
  "/* yy_hold_char holds the character lost when yytext is formed. */",
  "static char yy_hold_char;",
  "",
  "static int yy_n_chars;		/* number of characters read into yy_ch_buf */",
  "",
  "",
  "int yyleng;",
  "",
  "/* Points to current character in buffer. */",
  "static char *yy_c_buf_p = (char *) 0;",
  "static int yy_init = 1;		/* whether we need to initialize */",
  "static int yy_start = 0;	/* start state number */",
  "",
  "/* Flag which is used to allow yywrap()'s to do buffer switches",
  " * instead of setting up a fresh yyin.  A bit of a hack ...",
  " */",
  "static int yy_did_buffer_switch_on_eof;",
  "",
  "static void yyunput YY_PROTO(( int c, char *buf_ptr ));",
  "void yyrestart YY_PROTO(( FILE *input_file ));",
  "void yy_switch_to_buffer YY_PROTO(( YY_BUFFER_STATE new_buffer ));",
  "void yy_load_buffer_state YY_PROTO(( void ));",
  "YY_BUFFER_STATE yy_create_buffer YY_PROTO(( FILE *file, int size ));",
  "void yy_delete_buffer YY_PROTO(( YY_BUFFER_STATE b ));",
  "void yy_init_buffer YY_PROTO(( YY_BUFFER_STATE b, FILE *file ));",
  "",
  "static int yy_start_stack_ptr = 0;",
  "static int yy_start_stack_depth = 0;",
  "static int *yy_start_stack = 0;",
  "static void yy_push_state YY_PROTO(( int new_state ));",
  "static void yy_pop_state YY_PROTO(( void ));",
  "static int yy_top_state YY_PROTO(( void ));",
  "%*",
  "",
  "static void *yy_flex_alloc YY_PROTO(( unsigned int ));",
  "static void *yy_flex_realloc YY_PROTO(( void *, unsigned int ));",
  "static void yy_flex_free YY_PROTO(( void * ));",
  "",
  "#define yy_new_buffer yy_create_buffer",
  "",
  "%% yytext/yyin/yyout/yy_state_type/yylineno etc. def's & init go here",
  "",
  "#ifndef yytext_ptr",
  "static void yy_flex_strncpy YY_PROTO(( char *, const char *, int ));",
  "#endif",
  "",
  "%- Standard (non-C++) definition",
  "#ifdef __cplusplus",
  "static int yyinput YY_PROTO(( void ));",
  "#else",
  "static int input YY_PROTO(( void ));",
  "#endif",
  "%*",
  "",
  "%- Standard (non-C++) definition",
  "static yy_state_type yy_get_previous_state YY_PROTO(( void ));",
  "static yy_state_type yy_try_NUL_trans YY_PROTO(( yy_state_type current_state ));",
  "static int yy_get_next_buffer YY_PROTO(( void ));",
  "static void yy_fatal_error YY_PROTO(( const char msg[] ));",
  "%*",
  "",
  "/* Done after the current pattern has been matched and before the",
  " * corresponding action - sets up yytext.",
  " */",
  "#define YY_DO_BEFORE_ACTION \\",
  "	yytext_ptr = yy_bp; \\",
  "%% code to fiddle yytext and yyleng for yymore() goes here",
  "	yy_hold_char = *yy_cp; \\",
  "	*yy_cp = '\\0'; \\",
  "%% code to copy yytext_ptr to yytext[] goes here, if %array",
  "	yy_c_buf_p = yy_cp;",
  "",
  "%% data tables for the DFA and the user's section 1 definitions go here",
  "",
  "/* Macros after this point can all be overridden by user definitions in",
  " * section 1.",
  " */",
  "",
  "#ifdef YY_MALLOC_DECL",
  "YY_MALLOC_DECL",
  "#else",
  "#if __STDC__",
  "#ifndef __cplusplus",
  "#include <stdlib.h>",
  "#endif",
  "#else",
  "/* Just try to get by without declaring the routines.  This will fail",
  " * miserably on non-ANSI systems for which sizeof(size_t) != sizeof(int)",
  " * or sizeof(void*) != sizeof(int).",
  " */",
  "#endif",
  "#endif",
  "",
  "/* Amount of stuff to slurp up with each read. */",
  "#ifndef YY_READ_BUF_SIZE",
  "#define YY_READ_BUF_SIZE 8192",
  "#endif",
  "",
  "/* Copy whatever the last rule matched to the standard output. */",
  "",
  "#ifndef ECHO",
  "%- Standard (non-C++) definition",
  "/* This used to be an fputs(), but since the string might contain NUL's,",
  " * we now use fwrite().",
  " */",
  "#define ECHO (void) fwrite( yytext, yyleng, 1, yyout )",
  "%+ C++ definition",
  "#define ECHO LexerOutput( yytext, yyleng )",
  "%*",
  "#endif",
  "",
  "/* Gets input and stuffs it into \"buf\".  number of characters read, or YY_NULL,",
  " * is returned in \"result\".",
  " */",
  "#ifndef YY_INPUT",
  "#define YY_INPUT(buf,result,max_size) \\",
  "%% fread()/read() definition of YY_INPUT goes here unless we're doing C++",
  "%+ C++ definition",
  "	if ( (result = LexerInput( (char *) buf, max_size )) < 0 ) \\",
  "		YY_FATAL_ERROR( \"input in flex scanner failed\" );",
  "%*",
  "#endif",
  "",
  "/* No semi-colon after return; correct usage is to write \"yyterminate();\" -",
  " * we don't want an extra ';' after the \"return\" because that will cause",
  " * some compilers to complain about unreachable statements.",
  " */",
  "#ifndef yyterminate",
  "#define yyterminate() return YY_NULL",
  "#endif",
  "",
  "/* Number of entries by which start-condition stack grows. */",
  "#ifndef YY_START_STACK_INCR",
  "#define YY_START_STACK_INCR 25",
  "#endif",
  "",
  "/* Report a fatal error. */",
  "#ifndef YY_FATAL_ERROR",
  "%-",
  "#define YY_FATAL_ERROR(msg) yy_fatal_error( msg )",
  "%+",
  "#define YY_FATAL_ERROR(msg) LexerError( msg )",
  "%*",
  "#endif",
  "",
  "/* Default declaration of generated scanner - a define so the user can",
  " * easily add parameters.",
  " */",
  "#ifndef YY_DECL",
  "%- Standard (non-C++) definition",
  "#define YY_DECL int yylex YY_PROTO(( void ))",
  "%+ C++ definition",
  "#define YY_DECL int yyFlexLexer::yylex()",
  "%*",
  "#endif",
  "",
  "/* Code executed at the beginning of each rule, after yytext and yyleng",
  " * have been set up.",
  " */",
  "#ifndef YY_USER_ACTION",
  "#define YY_USER_ACTION",
  "#endif",
  "",
  "/* Code executed at the end of each rule. */",
  "#ifndef YY_BREAK",
  "#define YY_BREAK break;",
  "#endif",
  "",
  "YY_DECL",
  "	{",
  "	register yy_state_type yy_current_state;",
  "	register char *yy_cp, *yy_bp;",
  "	register int yy_act;",
  "",
  "%% user's declarations go here",
  "",
  "	if ( yy_init )",
  "		{",
  "#ifdef YY_USER_INIT",
  "		YY_USER_INIT;",
  "#endif",
  "",
  "		if ( ! yy_start )",
  "			yy_start = 1;	/* first start state */",
  "",
  "		if ( ! yyin )",
  "%-",
  "			yyin = stdin;",
  "%+",
  "			yyin = &cin;",
  "%*",
  "",
  "		if ( ! yyout )",
  "%-",
  "			yyout = stdout;",
  "%+",
  "			yyout = &cout;",
  "%*",
  "",
  "		if ( yy_current_buffer )",
  "			yy_init_buffer( yy_current_buffer, yyin );",
  "		else",
  "			yy_current_buffer =",
  "				yy_create_buffer( yyin, YY_BUF_SIZE );",
  "",
  "		yy_load_buffer_state();",
  "",
  "		yy_init = 0;",
  "		}",
  "",
  "	while ( 1 )		/* loops until end-of-file is reached */",
  "		{",
  "%% yymore()-related code goes here",
  "		yy_cp = yy_c_buf_p;",
  "",
  "		/* Support of yytext. */",
  "		*yy_cp = yy_hold_char;",
  "",
  "		/* yy_bp points to the position in yy_ch_buf of the start of",
  "		 * the current run.",
  "		 */",
  "		yy_bp = yy_cp;",
  "",
  "%% code to set up and find next match goes here",
  "",
  "yy_find_action:",
  "%% code to find the action number goes here",
  "",
  "		YY_DO_BEFORE_ACTION;",
  "",
  "%% code for yylineno update goes here, if -l option",
  "",
  "do_action:	/* This label is used only to access EOF actions. */",
  "",
  "%% debug code goes here",
  "",
  "		switch ( yy_act )",
  "	{ /* beginning of action switch */",
  "%% actions go here",
  "",
  "	case YY_END_OF_BUFFER:",
  "		{",
  "		/* Amount of text matched not including the EOB char. */",
  "		int yy_amount_of_matched_text = yy_cp - yytext_ptr - 1;",
  "",
  "		/* Undo the effects of YY_DO_BEFORE_ACTION. */",
  "		*yy_cp = yy_hold_char;",
  "",
  "		if ( yy_current_buffer->yy_buffer_status == YY_BUFFER_NEW )",
  "			{",
  "			/* We're scanning a new file or input source.  It's",
  "			 * possible that this happened because the user",
  "			 * just pointed yyin at a new source and called",
  "			 * yylex().  If so, then we have to assure",
  "			 * consistency between yy_current_buffer and our",
  "			 * globals.  Here is the right place to do so, because",
  "			 * this is the first action (other than possibly a",
  "			 * back-up) that will match for the new input source.",
  "			 */",
  "			yy_n_chars = yy_current_buffer->yy_n_chars;",
  "			yy_current_buffer->yy_input_file = yyin;",
  "			yy_current_buffer->yy_buffer_status = YY_BUFFER_NORMAL;",
  "			}",
  "",
  "		/* Note that here we test for yy_c_buf_p \"<=\" to the position",
  "		 * of the first EOB in the buffer, since yy_c_buf_p will",
  "		 * already have been incremented past the NUL character",
  "		 * (since all states make transitions on EOB to the",
  "		 * end-of-buffer state).  Contrast this with the test",
  "		 * in input().",
  "		 */",
  "		if ( yy_c_buf_p <= &yy_current_buffer->yy_ch_buf[yy_n_chars] )",
  "			{ /* This was really a NUL. */",
  "			yy_state_type yy_next_state;",
  "",
  "			yy_c_buf_p = yytext_ptr + yy_amount_of_matched_text;",
  "",
  "			yy_current_state = yy_get_previous_state();",
  "",
  "			/* Okay, we're now positioned to make the NUL",
  "			 * transition.  We couldn't have",
  "			 * yy_get_previous_state() go ahead and do it",
  "			 * for us because it doesn't know how to deal",
  "			 * with the possibility of jamming (and we don't",
  "			 * want to build jamming into it because then it",
  "			 * will run more slowly).",
  "			 */",
  "",
  "			yy_next_state = yy_try_NUL_trans( yy_current_state );",
  "",
  "			yy_bp = yytext_ptr + YY_MORE_ADJ;",
  "",
  "			if ( yy_next_state )",
  "				{",
  "				/* Consume the NUL. */",
  "				yy_cp = ++yy_c_buf_p;",
  "				yy_current_state = yy_next_state;",
  "				goto yy_match;",
  "				}",
  "",
  "			else",
  "				{",
  "%% code to do back-up for compressed tables and set up yy_cp goes here",
  "				goto yy_find_action;",
  "				}",
  "			}",
  "",
  "		else switch ( yy_get_next_buffer() )",
  "			{",
  "			case EOB_ACT_END_OF_FILE:",
  "				{",
  "				yy_did_buffer_switch_on_eof = 0;",
  "",
  "				if ( yywrap() )",
  "					{",
  "					/* Note: because we've taken care in",
  "					 * yy_get_next_buffer() to have set up",
  "					 * yytext, we can now set up",
  "					 * yy_c_buf_p so that if some total",
  "					 * hoser (like flex itself) wants to",
  "					 * call the scanner after we return the",
  "					 * YY_NULL, it'll still work - another",
  "					 * YY_NULL will get returned.",
  "					 */",
  "					yy_c_buf_p = yytext_ptr + YY_MORE_ADJ;",
  "",
  "					yy_act = YY_STATE_EOF(YY_START);",
  "					goto do_action;",
  "					}",
  "",
  "				else",
  "					{",
  "					if ( ! yy_did_buffer_switch_on_eof )",
  "						YY_NEW_FILE;",
  "					}",
  "				break;",
  "				}",
  "",
  "			case EOB_ACT_CONTINUE_SCAN:",
  "				yy_c_buf_p =",
  "					yytext_ptr + yy_amount_of_matched_text;",
  "",
  "				yy_current_state = yy_get_previous_state();",
  "",
  "				yy_cp = yy_c_buf_p;",
  "				yy_bp = yytext_ptr + YY_MORE_ADJ;",
  "				goto yy_match;",
  "",
  "			case EOB_ACT_LAST_MATCH:",
  "				yy_c_buf_p =",
  "				&yy_current_buffer->yy_ch_buf[yy_n_chars];",
  "",
  "				yy_current_state = yy_get_previous_state();",
  "",
  "				yy_cp = yy_c_buf_p;",
  "				yy_bp = yytext_ptr + YY_MORE_ADJ;",
  "				goto yy_find_action;",
  "			}",
  "		break;",
  "		}",
  "",
  "	default:",
  "		YY_FATAL_ERROR(",
  "			\"fatal flex scanner internal error--no action found\" );",
  "	} /* end of action switch */",
  "		} /* end of scanning one token */",
  "	} /* end of yylex */",
  "",
  "%+",
  "#ifdef YY_INTERACTIVE",
  "int yyFlexLexer::LexerInput( char* buf, int /* max_size */ )",
  "#else",
  "int yyFlexLexer::LexerInput( char* buf, int max_size )",
  "#endif",
  "	{",
  "	if ( yyin->eof() || yyin->fail() )",
  "		return 0;",
  "",
  "#ifdef YY_INTERACTIVE",
  "	yyin->get( buf[0] );",
  "",
  "	if ( yyin->eof() )",
  "		return 0;",
  "",
  "	if ( yyin->bad() )",
  "		return -1;",
  "",
  "	return 1;",
  "",
  "#else",
  "	(void) yyin->read( buf, max_size );",
  "",
  "	if ( yyin->bad() )",
  "		return -1;",
  "	else",
  "		return yyin->gcount();",
  "#endif",
  "	}",
  "",
  "void yyFlexLexer::LexerOutput( const char* buf, int size )",
  "	{",
  "	(void) yyout->write( buf, size );",
  "	}",
  "%*",
  "",
  "/* yy_get_next_buffer - try to read in a new buffer",
  " *",
  " * Returns a code representing an action:",
  " *	EOB_ACT_LAST_MATCH -",
  " *	EOB_ACT_CONTINUE_SCAN - continue scanning from current position",
  " *	EOB_ACT_END_OF_FILE - end of file",
  " */",
  "",
  "%-",
  "static int yy_get_next_buffer()",
  "%+",
  "int yyFlexLexer::yy_get_next_buffer()",
  "%*",
  "	{",
  "	register char *dest = yy_current_buffer->yy_ch_buf;",
  "	register char *source = yytext_ptr - 1; /* copy prev. char, too */",
  "	register int number_to_move, i;",
  "	int ret_val;",
  "",
  "	if ( yy_c_buf_p > &yy_current_buffer->yy_ch_buf[yy_n_chars + 1] )",
  "		YY_FATAL_ERROR(",
  "		\"fatal flex scanner internal error--end of buffer missed\" );",
  "",
  "	if ( yy_current_buffer->yy_fill_buffer == 0 )",
  "		{ /* Don't try to fill the buffer, so this is an EOF. */",
  "		if ( yy_c_buf_p - yytext_ptr - YY_MORE_ADJ == 1 )",
  "			{",
  "			/* We matched a singled characater, the EOB, so",
  "			 * treat this as a final EOF.",
  "			 */",
  "			return EOB_ACT_END_OF_FILE;",
  "			}",
  "",
  "		else",
  "			{",
  "			/* We matched some text prior to the EOB, first",
  "			 * process it.",
  "			 */",
  "			return EOB_ACT_LAST_MATCH;",
  "			}",
  "		}",
  "",
  "	/* Try to read more data. */",
  "",
  "	/* First move last chars to start of buffer. */",
  "	number_to_move = yy_c_buf_p - yytext_ptr;",
  "",
  "	for ( i = 0; i < number_to_move; ++i )",
  "		*(dest++) = *(source++);",
  "",
  "	if ( yy_current_buffer->yy_buffer_status == YY_BUFFER_EOF_PENDING )",
  "		/* don't do the read, it's not guaranteed to return an EOF,",
  "		 * just force an EOF",
  "		 */",
  "		yy_n_chars = 0;",
  "",
  "	else",
  "		{",
  "		int num_to_read =",
  "			yy_current_buffer->yy_buf_size - number_to_move - 1;",
  "",
  "		while ( num_to_read <= 0 )",
  "			{ /* Not enough room in the buffer - grow it. */",
  "#ifdef YY_USES_REJECT",
  "			YY_FATAL_ERROR(",
  "\"input buffer overflow, can't enlarge buffer because scanner uses REJECT\" );",
  "#else",
  "",
  "			/* just a shorter name for the current buffer */",
  "			YY_BUFFER_STATE b = yy_current_buffer;",
  "",
  "			int yy_c_buf_p_offset = yy_c_buf_p - b->yy_ch_buf;",
  "",
  "			b->yy_buf_size *= 2;",
  "			b->yy_ch_buf = (char *)",
  "				yy_flex_realloc( (void *) b->yy_ch_buf,",
  "						 b->yy_buf_size );",
  "",
  "			if ( ! b->yy_ch_buf )",
  "				YY_FATAL_ERROR(",
  "				\"fatal error - scanner input buffer overflow\" );",
  "",
  "			yy_c_buf_p = &b->yy_ch_buf[yy_c_buf_p_offset];",
  "",
  "			num_to_read = yy_current_buffer->yy_buf_size -",
  "						number_to_move - 1;",
  "#endif",
  "			}",
  "",
  "		if ( num_to_read > YY_READ_BUF_SIZE )",
  "			num_to_read = YY_READ_BUF_SIZE;",
  "",
  "		/* Read in more data. */",
  "		YY_INPUT( (&yy_current_buffer->yy_ch_buf[number_to_move]),",
  "			yy_n_chars, num_to_read );",
  "		}",
  "",
  "	if ( yy_n_chars == 0 )",
  "		{",
  "		if ( number_to_move - YY_MORE_ADJ == 1 )",
  "			{",
  "			ret_val = EOB_ACT_END_OF_FILE;",
  "			yyrestart( yyin );",
  "			}",
  "",
  "		else",
  "			{",
  "			ret_val = EOB_ACT_LAST_MATCH;",
  "			yy_current_buffer->yy_buffer_status =",
  "				YY_BUFFER_EOF_PENDING;",
  "			}",
  "		}",
  "",
  "	else",
  "		ret_val = EOB_ACT_CONTINUE_SCAN;",
  "",
  "	yy_n_chars += number_to_move;",
  "	yy_current_buffer->yy_ch_buf[yy_n_chars] = YY_END_OF_BUFFER_CHAR;",
  "	yy_current_buffer->yy_ch_buf[yy_n_chars + 1] = YY_END_OF_BUFFER_CHAR;",
  "",
  "	/* yytext begins at the second character in yy_ch_buf; the first",
  "	 * character is the one which preceded it before reading in the latest",
  "	 * buffer; it needs to be kept around in case it's a newline, so",
  "	 * yy_get_previous_state() will have with '^' rules active.",
  "	 */",
  "",
  "	yytext_ptr = &yy_current_buffer->yy_ch_buf[1];",
  "",
  "	return ret_val;",
  "	}",
  "",
  "",
  "/* yy_get_previous_state - get the state just before the EOB char was reached */",
  "",
  "%-",
  "static yy_state_type yy_get_previous_state()",
  "%+",
  "yy_state_type yyFlexLexer::yy_get_previous_state()",
  "%*",
  "	{",
  "	register yy_state_type yy_current_state;",
  "	register char *yy_cp;",
  "",
  "%% code to get the start state into yy_current_state goes here",
  "",
  "	for ( yy_cp = yytext_ptr + YY_MORE_ADJ; yy_cp < yy_c_buf_p; ++yy_cp )",
  "		{",
  "%% code to find the next state goes here",
  "		}",
  "",
  "	return yy_current_state;",
  "	}",
  "",
  "",
  "/* yy_try_NUL_trans - try to make a transition on the NUL character",
  " *",
  " * synopsis",
  " *	next_state = yy_try_NUL_trans( current_state );",
  " */",
  "",
  "%-",
  "#ifdef YY_USE_PROTOS",
  "static yy_state_type yy_try_NUL_trans( yy_state_type yy_current_state )",
  "#else",
  "static yy_state_type yy_try_NUL_trans( yy_current_state )",
  "yy_state_type yy_current_state;",
  "#endif",
  "%+",
  "yy_state_type yyFlexLexer::yy_try_NUL_trans( yy_state_type yy_current_state )",
  "%*",
  "	{",
  "	register int yy_is_jam;",
  "%% code to find the next state, and perhaps do backing up, goes here",
  "",
  "	return yy_is_jam ? 0 : yy_current_state;",
  "	}",
  "",
  "",
  "%-",
  "#ifdef YY_USE_PROTOS",
  "static void yyunput( int c, register char *yy_bp )",
  "#else",
  "static void yyunput( c, yy_bp )",
  "int c;",
  "register char *yy_bp;",
  "#endif",
  "%+",
  "void yyFlexLexer::yyunput( int c, register char* yy_bp )",
  "%*",
  "	{",
  "	register char *yy_cp = yy_c_buf_p;",
  "",
  "	/* undo effects of setting up yytext */",
  "	*yy_cp = yy_hold_char;",
  "",
  "	if ( yy_cp < yy_current_buffer->yy_ch_buf + 2 )",
  "		{ /* need to shift things up to make room */",
  "		/* +2 for EOB chars. */",
  "		register int number_to_move = yy_n_chars + 2;",
  "		register char *dest = &yy_current_buffer->yy_ch_buf[",
  "					yy_current_buffer->yy_buf_size + 2];",
  "		register char *source =",
  "				&yy_current_buffer->yy_ch_buf[number_to_move];",
  "",
  "		while ( source > yy_current_buffer->yy_ch_buf )",
  "			*--dest = *--source;",
  "",
  "		yy_cp += dest - source;",
  "		yy_bp += dest - source;",
  "		yy_n_chars = yy_current_buffer->yy_buf_size;",
  "",
  "		if ( yy_cp < yy_current_buffer->yy_ch_buf + 2 )",
  "			YY_FATAL_ERROR( \"flex scanner push-back overflow\" );",
  "		}",
  "",
  "	if ( yy_cp > yy_bp && yy_cp[-1] == '\\n' )",
  "		yy_cp[-2] = '\\n';",
  "",
  "	*--yy_cp = (char) c;",
  "",
  "%% update yylineno here, if doing -l",
  "",
  "	/* Note: the formal parameter *must* be called \"yy_bp\" for this",
  "	 * macro to now work correctly.",
  "	 */",
  "	YY_DO_BEFORE_ACTION; /* set up yytext again */",
  "	}",
  "",
  "",
  "%-",
  "#ifdef __cplusplus",
  "static int yyinput()",
  "#else",
  "static int input()",
  "#endif",
  "%+",
  "int yyFlexLexer::yyinput()",
  "%*",
  "	{",
  "	int c;",
  "",
  "	*yy_c_buf_p = yy_hold_char;",
  "",
  "	if ( *yy_c_buf_p == YY_END_OF_BUFFER_CHAR )",
  "		{",
  "		/* yy_c_buf_p now points to the character we want to return.",
  "		 * If this occurs *before* the EOB characters, then it's a",
  "		 * valid NUL; if not, then we've hit the end of the buffer.",
  "		 */",
  "		if ( yy_c_buf_p < &yy_current_buffer->yy_ch_buf[yy_n_chars] )",
  "			/* This was really a NUL. */",
  "			*yy_c_buf_p = '\\0';",
  "",
  "		else",
  "			{ /* need more input */",
  "			yytext_ptr = yy_c_buf_p;",
  "			++yy_c_buf_p;",
  "",
  "			switch ( yy_get_next_buffer() )",
  "				{",
  "				case EOB_ACT_END_OF_FILE:",
  "					{",
  "					if ( yywrap() )",
  "						{",
  "						yy_c_buf_p =",
  "						yytext_ptr + YY_MORE_ADJ;",
  "						return EOF;",
  "						}",
  "",
  "					YY_NEW_FILE;",
  "#ifdef __cplusplus",
  "					return yyinput();",
  "#else",
  "					return input();",
  "#endif",
  "					}",
  "",
  "				case EOB_ACT_CONTINUE_SCAN:",
  "					yy_c_buf_p = yytext_ptr + YY_MORE_ADJ;",
  "					break;",
  "",
  "				case EOB_ACT_LAST_MATCH:",
  "#ifdef __cplusplus",
  "					YY_FATAL_ERROR(",
  "					\"unexpected last match in yyinput()\" );",
  "#else",
  "					YY_FATAL_ERROR(",
  "					\"unexpected last match in input()\" );",
  "#endif",
  "				}",
  "			}",
  "		}",
  "",
  "	c = *(unsigned char *) yy_c_buf_p;	/* cast for 8-bit char's */",
  "	*yy_c_buf_p = '\\0';	/* preserve yytext */",
  "	yy_hold_char = *++yy_c_buf_p;",
  "",
  "	return c;",
  "	}",
  "",
  "",
  "%-",
  "#ifdef YY_USE_PROTOS",
  "void yyrestart( FILE *input_file )",
  "#else",
  "void yyrestart( input_file )",
  "FILE *input_file;",
  "#endif",
  "%+",
  "void yyFlexLexer::yyrestart( istream* input_file )",
  "%*",
  "	{",
  "	if ( ! yy_current_buffer )",
  "		yy_current_buffer = yy_create_buffer( yyin, YY_BUF_SIZE );",
  "",
  "	yy_init_buffer( yy_current_buffer, input_file );",
  "	yy_load_buffer_state();",
  "	}",
  "",
  "",
  "%-",
  "#ifdef YY_USE_PROTOS",
  "void yy_switch_to_buffer( YY_BUFFER_STATE new_buffer )",
  "#else",
  "void yy_switch_to_buffer( new_buffer )",
  "YY_BUFFER_STATE new_buffer;",
  "#endif",
  "%+",
  "void yyFlexLexer::yy_switch_to_buffer( YY_BUFFER_STATE new_buffer )",
  "%*",
  "	{",
  "	if ( yy_current_buffer == new_buffer )",
  "		return;",
  "",
  "	if ( yy_current_buffer )",
  "		{",
  "		/* Flush out information for old buffer. */",
  "		*yy_c_buf_p = yy_hold_char;",
  "		yy_current_buffer->yy_buf_pos = yy_c_buf_p;",
  "		yy_current_buffer->yy_n_chars = yy_n_chars;",
  "		}",
  "",
  "	yy_current_buffer = new_buffer;",
  "	yy_load_buffer_state();",
  "",
  "	/* We don't actually know whether we did this switch during",
  "	 * EOF (yywrap()) processing, but the only time this flag",
  "	 * is looked at is after yywrap() is called, so it's safe",
  "	 * to go ahead and always set it.",
  "	 */",
  "	yy_did_buffer_switch_on_eof = 1;",
  "	}",
  "",
  "",
  "%-",
  "#ifdef YY_USE_PROTOS",
  "void yy_load_buffer_state( void )",
  "#else",
  "void yy_load_buffer_state()",
  "#endif",
  "%+",
  "void yyFlexLexer::yy_load_buffer_state()",
  "%*",
  "	{",
  "	yy_n_chars = yy_current_buffer->yy_n_chars;",
  "	yytext_ptr = yy_c_buf_p = yy_current_buffer->yy_buf_pos;",
  "	yyin = yy_current_buffer->yy_input_file;",
  "	yy_hold_char = *yy_c_buf_p;",
  "	}",
  "",
  "",
  "%-",
  "#ifdef YY_USE_PROTOS",
  "YY_BUFFER_STATE yy_create_buffer( FILE *file, int size )",
  "#else",
  "YY_BUFFER_STATE yy_create_buffer( file, size )",
  "FILE *file;",
  "int size;",
  "#endif",
  "%+",
  "YY_BUFFER_STATE yyFlexLexer::yy_create_buffer( istream* file, int size )",
  "%*",
  "	{",
  "	YY_BUFFER_STATE b;",
  "",
  "	b = (YY_BUFFER_STATE) yy_flex_alloc( sizeof( struct yy_buffer_state ) );",
  "",
  "	if ( ! b )",
  "		YY_FATAL_ERROR( \"out of dynamic memory in yy_create_buffer()\" );",
  "",
  "	b->yy_buf_size = size;",
  "",
  "	/* yy_ch_buf has to be 2 characters longer than the size given because",
  "	 * we need to put in 2 end-of-buffer characters.",
  "	 */",
  "	b->yy_ch_buf = (char *) yy_flex_alloc( b->yy_buf_size + 2 );",
  "",
  "	if ( ! b->yy_ch_buf )",
  "		YY_FATAL_ERROR( \"out of dynamic memory in yy_create_buffer()\" );",
  "",
  "	yy_init_buffer( b, file );",
  "",
  "	return b;",
  "	}",
  "",
  "",
  "%-",
  "#ifdef YY_USE_PROTOS",
  "void yy_delete_buffer( YY_BUFFER_STATE b )",
  "#else",
  "void yy_delete_buffer( b )",
  "YY_BUFFER_STATE b;",
  "#endif",
  "%+",
  "void yyFlexLexer::yy_delete_buffer( YY_BUFFER_STATE b )",
  "%*",
  "	{",
  "	if ( b == yy_current_buffer )",
  "		yy_current_buffer = (YY_BUFFER_STATE) 0;",
  "",
  "	yy_flex_free( (void *) b->yy_ch_buf );",
  "	yy_flex_free( (void *) b );",
  "	}",
  "",
  "",
  "%-",
  "#ifdef YY_USE_PROTOS",
  "void yy_init_buffer( YY_BUFFER_STATE b, FILE *file )",
  "#else",
  "void yy_init_buffer( b, file )",
  "YY_BUFFER_STATE b;",
  "FILE *file;",
  "#endif",
  "%+",
  "void yyFlexLexer::yy_init_buffer( YY_BUFFER_STATE b, istream* file )",
  "%*",
  "	{",
  "	b->yy_input_file = file;",
  "",
  "	/* We put in the '\\n' and start reading from [1] so that an",
  "	 * initial match-at-newline will be true.",
  "	 */",
  "",
  "	b->yy_ch_buf[0] = '\\n';",
  "	b->yy_n_chars = 1;",
  "",
  "	/* We always need two end-of-buffer characters.  The first causes",
  "	 * a transition to the end-of-buffer state.  The second causes",
  "	 * a jam in that state.",
  "	 */",
  "	b->yy_ch_buf[1] = YY_END_OF_BUFFER_CHAR;",
  "	b->yy_ch_buf[2] = YY_END_OF_BUFFER_CHAR;",
  "",
  "	b->yy_buf_pos = &b->yy_ch_buf[1];",
  "",
  "%-",
  "	b->yy_is_interactive = file ? isatty( fileno(file) ) : 0;",
  "%+",
  "	b->yy_is_interactive = 0;",
  "%*",
  "",
  "	b->yy_fill_buffer = 1;",
  "",
  "	b->yy_buffer_status = YY_BUFFER_NEW;",
  "	}",
  "",
  "",
  "%-",
  "#ifdef YY_USE_PROTOS",
  "static void yy_push_state( int new_state )",
  "#else",
  "static void yy_push_state( new_state )",
  "int new_state;",
  "#endif",
  "%+",
  "void yyFlexLexer::yy_push_state( int new_state )",
  "%*",
  "	{",
  "	if ( yy_start_stack_ptr >= yy_start_stack_depth )",
  "		{",
  "		int new_size;",
  "",
  "		yy_start_stack_depth += YY_START_STACK_INCR;",
  "		new_size = yy_start_stack_depth * sizeof( int );",
  "",
  "		if ( ! yy_start_stack )",
  "			yy_start_stack = (int *) yy_flex_alloc( new_size );",
  "",
  "		else",
  "			yy_start_stack = (int *) yy_flex_realloc(",
  "					(void *) yy_start_stack, new_size );",
  "",
  "		if ( ! yy_start_stack )",
  "			YY_FATAL_ERROR(",
  "			\"out of memory expanding start-condition stack\" );",
  "		}",
  "",
  "	yy_start_stack[yy_start_stack_ptr++] = YY_START;",
  "",
  "	BEGIN(new_state);",
  "	}",
  "",
  "",
  "%-",
  "static void yy_pop_state()",
  "%+",
  "void yyFlexLexer::yy_pop_state()",
  "%*",
  "	{",
  "	if ( --yy_start_stack_ptr < 0 )",
  "		YY_FATAL_ERROR( \"start-condition stack underflow\" );",
  "",
  "	BEGIN(yy_start_stack[yy_start_stack_ptr]);",
  "	}",
  "",
  "",
  "%-",
  "static int yy_top_state()",
  "%+",
  "int yyFlexLexer::yy_top_state()",
  "%*",
  "	{",
  "	return yy_start_stack[yy_start_stack_ptr - 1];",
  "	}",
  "",
  "",
  "%-",
  "#ifdef YY_USE_PROTOS",
  "static void yy_fatal_error( const char msg[] )",
  "#else",
  "static void yy_fatal_error( msg )",
  "char msg[];",
  "#endif",
  "	{",
  "FILE *err;",
  "	(void) fprintf( err, \"%s\\n\", msg );",
  "	exit( 1 );",
  "	}",
  "",
  "%+",
  "",
  "void yyFlexLexer::LexerError( const char msg[] )",
  "	{",
  "	cerr << msg << '\\n';",
  "	exit( 1 );",
  "	}",
  "%*",
  "",
  "",
  "/* Redefine yyless() so it works in section 3 code. */",
  "",
  "#undef yyless",
  "#define yyless(n) \\",
  "	do \\",
  "		{ \\",
  "		/* Undo effects of setting up yytext. */ \\",
  "		yytext[yyleng] = yy_hold_char; \\",
  "		yy_c_buf_p = yytext + n - YY_MORE_ADJ; \\",
  "		yy_hold_char = *yy_c_buf_p; \\",
  "		*yy_c_buf_p = '\\0'; \\",
  "		yyleng = n; \\",
  "		} \\",
  "	while ( 0 )",
  "",
  "",
  "/* Internal utility routines. */",
  "",
  "#ifndef yytext_ptr",
  "#ifdef YY_USE_PROTOS",
  "static void yy_flex_strncpy( char *s1, const char *s2, int n )",
  "#else",
  "static void yy_flex_strncpy( s1, s2, n )",
  "char *s1;",
  "const char *s2;",
  "int n;",
  "#endif",
  "	{",
  "	register int i;",
  "	for ( i = 0; i < n; ++i )",
  "		s1[i] = s2[i];",
  "	}",
  "#endif",
  "",
  "",
  "#ifdef YY_USE_PROTOS",
  "static void *yy_flex_alloc( unsigned int size )",
  "#else",
  "static void *yy_flex_alloc( size )",
  "unsigned int size;",
  "#endif",
  "	{",
  "	return (void *) malloc( size );",
  "	}",
  "",
  "#ifdef YY_USE_PROTOS",
  "static void *yy_flex_realloc( void *ptr, unsigned int size )",
  "#else",
  "static void *yy_flex_realloc( ptr, size )",
  "void *ptr;",
  "unsigned int size;",
  "#endif",
  "	{",
  "	return (void *) realloc( ptr, size );",
  "	}",
  "",
  "#ifdef YY_USE_PROTOS",
  "static void yy_flex_free( void *ptr )",
  "#else",
  "static void yy_flex_free( ptr )",
  "void *ptr;",
  "#endif",
  "	{",
  "	free( ptr );",
  "	}",
  0
};
int hashfunct (register char[], int);
struct hash_entry *ndtbl[101];
struct hash_entry *sctbl[101];
struct hash_entry *ccltab[101];
struct hash_entry *findsym();
int addsym( sym, str_def, int_def, table, table_size )
register char sym[];
char *str_def;
int int_def;
hash_table table;
int table_size;
 {
 int hash_val = hashfunct( sym, table_size );
 register struct hash_entry *sym_entry = table[hash_val];
 register struct hash_entry *new_entry;
 register struct hash_entry *successor;
 while ( sym_entry )
  {
  if ( ! strcmp( sym, sym_entry->name ) )
   {
   return -1;
   }
  sym_entry = sym_entry->next;
  }
 new_entry = (struct hash_entry *)
  flex_alloc( sizeof( struct hash_entry ) );
 if ( new_entry == ((void *)0) )
  flexfatal( "symbol table memory allocation failed" );
 if ( (successor = table[hash_val]) )
  {
  new_entry->next = successor;
  successor->prev = new_entry;
  }
 else
  new_entry->next = ((void *)0);
 new_entry->prev = ((void *)0);
 new_entry->name = sym;
 new_entry->str_val = str_def;
 new_entry->int_val = int_def;
 table[hash_val] = new_entry;
 return 0;
 }
void cclinstal( ccltxt, cclnum )
unsigned char ccltxt[];
int cclnum;
 {
 unsigned char *copy_unsigned_string();
 (void) addsym( (char *) copy_unsigned_string( ccltxt ),
   (char *) 0, cclnum,
   ccltab, 101 );
 }
int ccllookup( ccltxt )
unsigned char ccltxt[];
 {
 return findsym( (char *) ccltxt, ccltab, 101 )->int_val;
 }
struct hash_entry *findsym( sym, table, table_size )
register char sym[];
hash_table table;
int table_size;
 {
 static struct hash_entry empty_entry =
  {
  (struct hash_entry *) 0, (struct hash_entry *) 0,
  (char *) 0, (char *) 0, 0,
  } ;
 register struct hash_entry *sym_entry =
  table[hashfunct( sym, table_size )];
 while ( sym_entry )
  {
  if ( ! strcmp( sym, sym_entry->name ) )
   return sym_entry;
  sym_entry = sym_entry->next;
  }
 return &empty_entry;
 }
int hashfunct( str, hash_size )
register char str[];
int hash_size;
 {
 register int hashval;
 register int locstr;
 hashval = 0;
 locstr = 0;
 while ( str[locstr] )
  {
  hashval = (hashval << 1) + (unsigned char) str[locstr++];
  hashval %= hash_size;
  }
 return hashval;
 }
void ndinstal( name, definition )
char name[];
unsigned char definition[];
 {
 char *copy_string();
 unsigned char *copy_unsigned_string();
 if ( addsym( copy_string( name ),
   (char *) copy_unsigned_string( definition ), 0,
   ndtbl, 101 ) )
  synerr( "name defined twice" );
 }
unsigned char *ndlookup( nd )
char nd[];
 {
 return (unsigned char *) findsym( nd, ndtbl, 101 )->str_val;
 }
void scextend()
 {
 current_max_scs += 40;
 ++num_reallocs;
 scset = (int *) reallocate_array( (void *) scset, current_max_scs, sizeof( int ) );
 scbol = (int *) reallocate_array( (void *) scbol, current_max_scs, sizeof( int ) );
 scxclu = (int *) reallocate_array( (void *) scxclu, current_max_scs, sizeof( int ) );
 sceof = (int *) reallocate_array( (void *) sceof, current_max_scs, sizeof( int ) );
 scname = (char **) reallocate_array( (void *) scname, current_max_scs, sizeof( char * ) );
 actvsc = (int *) reallocate_array( (void *) actvsc, current_max_scs, sizeof( int ) );
 }
void scinstal( str, xcluflg )
char str[];
int xcluflg;
 {
 char *copy_string();
 printf( "#define %s %d\n", str, lastsc );
 if ( ++lastsc >= current_max_scs )
  scextend();
 scname[lastsc] = copy_string( str );
 if ( addsym( scname[lastsc], (char *) 0, lastsc,
   sctbl, 101 ) )
  format_pinpoint_message( "start condition %s declared twice",
     str );
 scset[lastsc] = mkstate( (256 + 1) );
 scbol[lastsc] = mkstate( (256 + 1) );
 scxclu[lastsc] = xcluflg;
 sceof[lastsc] = 0;
 }
int sclookup( str )
char str[];
 {
 return findsym( str, sctbl, 101 )->int_val;
 }
void mkentry (register int*, int, int, int, int);
void mkprot (int[], int, int);
void mktemplate (int[], int, int);
void mv2front (int);
int tbldiff (int[], int, int[]);
void bldtbl( state, statenum, totaltrans, comstate, comfreq )
int state[], statenum, totaltrans, comstate, comfreq;
 {
 int extptr, extrct[2][256 + 1];
 int mindiff, minprot, i, d;
 extptr = 0;
 if ( (totaltrans * 100) < (numecs * 15) )
  mkentry( state, numecs, statenum, -32766, totaltrans );
 else
  {
  int checkcom =
   comfreq * 100 > totaltrans * 50;
  minprot = firstprot;
  mindiff = totaltrans;
  if ( checkcom )
   {
   for ( i = firstprot; i != 0; i = protnext[i] )
    if ( protcomst[i] == comstate )
     {
     minprot = i;
     mindiff = tbldiff( state, minprot,
       extrct[extptr] );
     break;
     }
   }
  else
   {
   comstate = 0;
   if ( firstprot != 0 )
    {
    minprot = firstprot;
    mindiff = tbldiff( state, minprot,
      extrct[extptr] );
    }
   }
  if ( mindiff * 100 > totaltrans * 10 )
   {
   for ( i = minprot; i != 0; i = protnext[i] )
    {
    d = tbldiff( state, i, extrct[1 - extptr] );
    if ( d < mindiff )
     {
     extptr = 1 - extptr;
     mindiff = d;
     minprot = i;
     }
    }
   }
  if ( mindiff * 100 > totaltrans * 50 )
   {
   if ( comfreq * 100 >=
        totaltrans * 60 )
    mktemplate( state, statenum, comstate );
   else
    {
    mkprot( state, statenum, comstate );
    mkentry( state, numecs, statenum,
     -32766, totaltrans );
    }
   }
  else
   {
   mkentry( extrct[extptr], numecs, statenum,
    prottbl[minprot], mindiff );
   if ( mindiff * 100 >=
        totaltrans * 20 )
    mkprot( state, statenum, comstate );
   mv2front( minprot );
   }
  }
 }
void cmptmps()
 {
 int tmpstorage[256 + 1];
 register int *tmp = tmpstorage, i, j;
 int totaltrans, trans;
 peakpairs = numtemps * numecs + tblend;
 if ( usemecs )
  {
  nummecs = cre8ecs( tecfwd, tecbck, numecs );
  }
 else
  nummecs = numecs;
 while ( lastdfa + numtemps + 1 >= current_max_dfas )
  increase_max_dfas();
 for ( i = 1; i <= numtemps; ++i )
  {
  totaltrans = 0;
  for ( j = 1; j <= numecs; ++j )
   {
   trans = tnxt[numecs * i + j];
   if ( usemecs )
    {
    if ( tecbck[j] > 0 )
     {
     tmp[tecbck[j]] = trans;
     if ( trans > 0 )
      ++totaltrans;
     }
    }
   else
    {
    tmp[j] = trans;
    if ( trans > 0 )
     ++totaltrans;
    }
   }
  mkentry( tmp, nummecs, lastdfa + i + 1, -32766, totaltrans );
  }
 }
void expand_nxt_chk()
 {
 register int old_max = current_max_xpairs;
 current_max_xpairs += 2000;
 ++num_reallocs;
 nxt = (int *) reallocate_array( (void *) nxt, current_max_xpairs, sizeof( int ) );
 chk = (int *) reallocate_array( (void *) chk, current_max_xpairs, sizeof( int ) );
 zero_out( (char *) (chk + old_max),
  2000 * sizeof( int ) / sizeof( char ) );
 }
int find_table_space( state, numtrans )
int *state, numtrans;
 {
 register int i;
 register int *state_ptr, *chk_ptr;
 register int *ptr_to_last_entry_in_state;
 if ( numtrans > 4 )
  {
  if ( tblend < 2 )
   return 1;
  i = tblend - numecs;
  }
 else
  i = firstfree;
 while ( 1 )
  {
  while ( i + numecs >= current_max_xpairs )
   expand_nxt_chk();
  while ( 1 )
   {
   if ( chk[i - 1] == 0 )
    {
    if ( chk[i] == 0 )
     break;
    else
     i += 2;
    }
   else
    ++i;
   while ( i + numecs >= current_max_xpairs )
    expand_nxt_chk();
   }
  if ( numtrans <= 4 )
   firstfree = i + 1;
  state_ptr = &state[1];
  ptr_to_last_entry_in_state = &chk[i + numecs + 1];
  for ( chk_ptr = &chk[i + 1];
        chk_ptr != ptr_to_last_entry_in_state; ++chk_ptr )
   if ( *(state_ptr++) != 0 && *chk_ptr != 0 )
    break;
  if ( chk_ptr == ptr_to_last_entry_in_state )
   return i;
  else
  ++i;
  }
 }
void inittbl()
 {
 register int i;
 zero_out( (char *) chk,
  current_max_xpairs * sizeof( int ) / sizeof( char ) );
 tblend = 0;
 firstfree = tblend + 1;
 numtemps = 0;
 if ( usemecs )
  {
  tecbck[1] = 0;
  for ( i = 2; i <= numecs; ++i )
   {
   tecbck[i] = i - 1;
   tecfwd[i - 1] = i;
   }
  tecfwd[numecs] = 0;
  }
 }
void mkdeftbl()
 {
 int i;
 jamstate = lastdfa + 1;
 ++tblend;
 while ( tblend + numecs >= current_max_xpairs )
  expand_nxt_chk();
 nxt[tblend] = end_of_buffer_state;
 chk[tblend] = jamstate;
 for ( i = 1; i <= numecs; ++i )
  {
  nxt[tblend + i] = 0;
  chk[tblend + i] = jamstate;
  }
 jambase = tblend;
 base[jamstate] = jambase;
 def[jamstate] = 0;
 tblend += numecs;
 ++numtemps;
 }
void mkentry( state, numchars, statenum, deflink, totaltrans )
register int *state;
int numchars, statenum, deflink, totaltrans;
 {
 register int minec, maxec, i, baseaddr;
 int tblbase, tbllast;
 if ( totaltrans == 0 )
  {
  if ( deflink == -32766 )
   base[statenum] = -32766;
  else
   base[statenum] = 0;
  def[statenum] = deflink;
  return;
  }
 for ( minec = 1; minec <= numchars; ++minec )
  {
  if ( state[minec] != -1 )
   if ( state[minec] != 0 || deflink != -32766 )
    break;
  }
 if ( totaltrans == 1 )
  {
  stack1( statenum, minec, state[minec], deflink );
  return;
  }
 for ( maxec = numchars; maxec > 0; --maxec )
  {
  if ( state[maxec] != -1 )
   if ( state[maxec] != 0 || deflink != -32766 )
    break;
  }
 if ( totaltrans * 100 <= numchars * 15 )
  {
  baseaddr = firstfree;
  while ( baseaddr < minec )
   {
   for ( ++baseaddr; chk[baseaddr] != 0; ++baseaddr )
    ;
   }
  while ( baseaddr + maxec - minec + 1 >= current_max_xpairs )
   expand_nxt_chk();
  for ( i = minec; i <= maxec; ++i )
   if ( state[i] != -1 &&
        (state[i] != 0 || deflink != -32766) &&
        chk[baseaddr + i - minec] != 0 )
    {
    for ( ++baseaddr;
          baseaddr < current_max_xpairs &&
          chk[baseaddr] != 0; ++baseaddr )
     ;
    while ( baseaddr + maxec - minec + 1 >=
     current_max_xpairs )
     expand_nxt_chk();
    i = minec - 1;
    }
  }
 else
  {
  baseaddr = ((tblend + 1) > (minec) ? (tblend + 1) : (minec));
  }
 tblbase = baseaddr - minec;
 tbllast = tblbase + maxec;
 while ( tbllast + 1 >= current_max_xpairs )
  expand_nxt_chk();
 base[statenum] = tblbase;
 def[statenum] = deflink;
 for ( i = minec; i <= maxec; ++i )
  if ( state[i] != -1 )
   if ( state[i] != 0 || deflink != -32766 )
    {
    nxt[tblbase + i] = state[i];
    chk[tblbase + i] = statenum;
    }
 if ( baseaddr == firstfree )
  for ( ++firstfree; chk[firstfree] != 0; ++firstfree )
   ;
 tblend = ((tblend) > (tbllast) ? (tblend) : (tbllast));
 }
void mk1tbl( state, sym, onenxt, onedef )
int state, sym, onenxt, onedef;
 {
 if ( firstfree < sym )
  firstfree = sym;
 while ( chk[firstfree] != 0 )
  if ( ++firstfree >= current_max_xpairs )
   expand_nxt_chk();
 base[state] = firstfree - sym;
 def[state] = onedef;
 chk[firstfree] = state;
 nxt[firstfree] = onenxt;
 if ( firstfree > tblend )
  {
  tblend = firstfree++;
  if ( firstfree >= current_max_xpairs )
   expand_nxt_chk();
  }
 }
void mkprot( state, statenum, comstate )
int state[], statenum, comstate;
 {
 int i, slot, tblbase;
 if ( ++numprots >= 50 || numecs * numprots >= 2000 )
  {
  slot = lastprot;
  lastprot = protprev[lastprot];
  protnext[lastprot] = 0;
  }
 else
  slot = numprots;
 protnext[slot] = firstprot;
 if ( firstprot != 0 )
  protprev[firstprot] = slot;
 firstprot = slot;
 prottbl[slot] = statenum;
 protcomst[slot] = comstate;
 tblbase = numecs * (slot - 1);
 for ( i = 1; i <= numecs; ++i )
  protsave[tblbase + i] = state[i];
 }
void mktemplate( state, statenum, comstate )
int state[], statenum, comstate;
 {
 int i, numdiff, tmpbase, tmp[256 + 1];
 unsigned char transset[256 + 1];
 int tsptr;
 ++numtemps;
 tsptr = 0;
 tmpbase = numtemps * numecs;
 if ( tmpbase + numecs >= current_max_template_xpairs )
  {
  current_max_template_xpairs += 2500;
  ++num_reallocs;
  tnxt = (int *) reallocate_array( (void *) tnxt, current_max_template_xpairs, sizeof( int ) );
  }
 for ( i = 1; i <= numecs; ++i )
  if ( state[i] == 0 )
   tnxt[tmpbase + i] = 0;
  else
   {
   transset[tsptr++] = i;
   tnxt[tmpbase + i] = comstate;
   }
 if ( usemecs )
  mkeccl( transset, tsptr, tecfwd, tecbck, numecs, 0 );
 mkprot( tnxt + tmpbase, -numtemps, comstate );
 numdiff = tbldiff( state, firstprot, tmp );
 mkentry( tmp, numecs, statenum, -numtemps, numdiff );
 }
void mv2front( qelm )
int qelm;
 {
 if ( firstprot != qelm )
  {
  if ( qelm == lastprot )
   lastprot = protprev[lastprot];
  protnext[protprev[qelm]] = protnext[qelm];
  if ( protnext[qelm] != 0 )
   protprev[protnext[qelm]] = protprev[qelm];
  protprev[qelm] = 0;
  protnext[qelm] = firstprot;
  protprev[firstprot] = qelm;
  firstprot = qelm;
  }
 }
void place_state( state, statenum, transnum )
int *state, statenum, transnum;
 {
 register int i;
 register int *state_ptr;
 int position = find_table_space( state, transnum );
 base[statenum] = position;
 chk[position - 1] = 1;
 chk[position] = 1;
 state_ptr = &state[1];
 for ( i = 1; i <= numecs; ++i, ++state_ptr )
  if ( *state_ptr != 0 )
   {
   chk[position + i] = i;
   nxt[position + i] = *state_ptr;
   }
 if ( position + numecs > tblend )
  tblend = position + numecs;
 }
void stack1( statenum, sym, nextstate, deflink )
int statenum, sym, nextstate, deflink;
 {
 if ( onesp >= 500 - 1 )
  mk1tbl( statenum, sym, nextstate, deflink );
 else
  {
  ++onesp;
  onestate[onesp] = statenum;
  onesym[onesp] = sym;
  onenext[onesp] = nextstate;
  onedef[onesp] = deflink;
  }
 }
int tbldiff( state, pr, ext )
int state[], pr, ext[];
 {
 register int i, *sp = state, *ep = ext, *protp;
 register int numdiff = 0;
 protp = &protsave[numecs * (pr - 1)];
 for ( i = numecs; i > 0; --i )
  {
  if ( *++protp == *++sp )
   *++ep = -1;
  else
   {
   *++ep = *sp;
   ++numdiff;
   }
  }
 return numdiff;
 }
int yylex()
 {
 int toktype;
 static int beglin = 0;
 if ( eofseen )
  toktype = (-1);
 else
  toktype = flexscan();
 if ( toktype == (-1) || toktype == 0 )
  {
  eofseen = 1;
  if ( sectnum == 1 )
   {
   synerr( "premature EOF" );
   sectnum = 2;
   toktype = 259;
   }
  else
   toktype = 0;
  }
 if ( trace )
  {
  if ( beglin )
   {
   fprintf( err, "%d\t", num_rules + 1 );
   beglin = 0;
   }
  switch ( toktype )
   {
   case '<':
   case '>':
   case '^':
   case '$':
   case '"':
   case '[':
   case ']':
   case '{':
   case '}':
   case '|':
   case '(':
   case ')':
   case '-':
   case '/':
   case '\\':
   case '?':
   case '.':
   case '*':
   case '+':
   case ',':
    (void) _IO_putc (toktype, err);
    break;
   case '\n':
    (void) _IO_putc ('\n', err);
    if ( sectnum == 2 )
    beglin = 1;
    break;
   case 260:
    fputs( "%s", err );
    break;
   case 261:
    fputs( "%x", err );
    break;
   case 262:
    (void) _IO_putc (' ', err);
    break;
   case 259:
    fputs( "%%\n", err );
    if ( sectnum == 2 )
    beglin = 1;
    break;
   case 263:
    fprintf( err, "'%s'", nmstr );
    break;
   case 257:
    switch ( yylval )
     {
     case '<':
     case '>':
     case '^':
     case '$':
     case '"':
     case '[':
     case ']':
     case '{':
     case '}':
     case '|':
     case '(':
     case ')':
     case '-':
     case '/':
     case '\\':
     case '?':
     case '.':
     case '*':
     case '+':
     case ',':
      fprintf( err, "\\%c",
       yylval );
      break;
     default:
      if ( ! (((yylval) & ~0x7f) == 0) ||
           ! ((*__ctype_b_loc ())[(int) ((yylval))] & (unsigned short int) _ISprint) )
       fprintf( err,
        "\\%.3o",
       (unsigned int) yylval );
      else
       (void) _IO_putc (yylval, err);
     break;
     }
    break;
   case 258:
    fprintf( err, "%d", yylval );
    break;
   case 264:
    fprintf( err, "[%d]", yylval );
    break;
   case 265:
    fprintf( err, "<<EOF>>" );
    break;
   case 0:
    fprintf( err, "End Marker" );
    break;
   default:
    fprintf( err,
     "*Something Weird* - tok: %d val: %d\n",
     toktype, yylval );
    break;
   }
  }
 return toktype;
 }
int pat, scnum, eps, headcnt, trailcnt, anyccl, lastchar, i, actvp, rulelen;
int trlcontxt, xcluflg, cclsorted, varlength, variable_trail_rule;
int *active_ss;
unsigned char clower();
void build_eof_action();
void yyerror();
static int madeany = 0;
int previous_continued_action;
static const char yytranslate[] = { 0,
     2, 2, 2, 2, 2, 2, 2, 2, 2, 12,
     2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
     2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
     2, 2, 2, 26, 2, 18, 2, 2, 2, 27,
    28, 16, 21, 17, 31, 25, 20, 2, 2, 2,
     2, 2, 2, 2, 2, 2, 2, 2, 2, 14,
     2, 15, 22, 2, 2, 2, 2, 2, 2, 2,
     2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
     2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    29, 2, 30, 13, 2, 2, 2, 2, 2, 2,
     2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
     2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
     2, 2, 23, 19, 24, 2, 2, 2, 2, 2,
     2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
     2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
     2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
     2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
     2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
     2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
     2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
     2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
     2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
     2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
     2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
     2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
     2, 2, 2, 2, 2, 1, 3, 4, 5, 6,
     7, 8, 9, 10, 11
};
static const short yyr1[] = { 0,
    32, 33, 34, 34, 34, 35, 36, 36, 37, 37,
    37, 38, 38, 39, 40, 40, 40, 40, 40, 40,
    40, 41, 41, 42, 43, 42, 42, 44, 45, 45,
    45, 45, 46, 46, 47, 48, 48, 49, 49, 49,
    49, 49, 49, 49, 49, 49, 49, 49, 49, 50,
    50, 51, 51, 51, 52, 52
};
static const short yyr2[] = { 0,
     5, 0, 5, 0, 2, 1, 1, 1, 3, 1,
     1, 4, 0, 0, 3, 2, 2, 1, 2, 1,
     1, 3, 3, 3, 0, 2, 1, 1, 2, 3,
     2, 1, 3, 1, 2, 2, 1, 2, 2, 2,
     6, 5, 4, 1, 1, 1, 3, 3, 1, 3,
     4, 4, 2, 0, 2, 0
};
static const short yydefact[] = { 2,
     0, 0, 0, 5, 6, 7, 8, 13, 0, 14,
     0, 0, 11, 10, 0, 21, 49, 46, 20, 0,
     0, 44, 56, 0, 54, 0, 0, 18, 32, 0,
    34, 37, 45, 0, 3, 17, 27, 0, 0, 0,
     0, 0, 54, 0, 12, 19, 0, 16, 31, 0,
    35, 29, 36, 38, 39, 40, 0, 9, 23, 22,
     0, 28, 26, 55, 47, 48, 0, 53, 50, 15,
    33, 30, 0, 24, 51, 0, 0, 43, 52, 0,
    42, 41, 0, 0, 0
};
static const short yydefgoto[] = { 83,
     1, 3, 8, 9, 15, 10, 12, 26, 27, 39,
    40, 63, 28, 29, 30, 31, 32, 33, 44, 41
};
static const short yypact[] = {-32768,
    61, -2, 64,-32768,-32768,-32768,-32768,-32768, 13,-32768,
    34, 1,-32768,-32768, 30,-32768,-32768,-32768,-32768, 21,
    48,-32768,-32768, 21, 31, 33, 26,-32768, 54, 21,
    21, 38,-32768, 47,-32768,-32768,-32768, 43, 5, 56,
    15, -11,-32768, 2,-32768,-32768, 21,-32768,-32768, 21,
-32768, 57, 38,-32768,-32768,-32768, 59,-32768,-32768,-32768,
    56,-32768,-32768,-32768,-32768,-32768, 4, 46,-32768,-32768,
    21,-32768, -8,-32768,-32768, 75, -1,-32768,-32768, 55,
-32768,-32768, 80, 81,-32768
};
static const short yypgoto[] = {-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768, 22, -14, -5,-32768, 32, -31,-32768, 41,-32768
};
static const short yytable[] = { 53,
    -1, 16, 80, 17, 68, 36, 68, 50, 77, 4,
    18, 19, 48, 20, 21, 78, 66, 64, 42, 60,
    11, 61, 81, 17, 52, 22, 23, 24, 17, 25,
    18, 69, 70, 75, 13, 18, 46, 34, 47, 53,
    65, 35, 14, 43, 45, 22, 23, 24, 37, 25,
    22, 23, 24, 54, 25, 58, -25, 59, 55, 56,
    57, 2, 73, 38, 62, -4, -4, -4, 5, 6,
     7, 49, 50, 51, 72, 50, 76, 79, 82, 84,
    85, 71, 74, 67
};
static const short yycheck[] = { 31,
     0, 1, 4, 3, 3, 20, 3, 19, 17, 12,
    10, 11, 27, 13, 14, 24, 28, 3, 24, 15,
     8, 17, 24, 3, 30, 25, 26, 27, 3, 29,
    10, 30, 47, 30, 1, 10, 11, 8, 13, 71,
    26, 12, 9, 13, 12, 25, 26, 27, 1, 29,
    25, 26, 27, 16, 29, 9, 9, 15, 21, 22,
    23, 1, 4, 16, 9, 5, 6, 7, 5, 6,
     7, 18, 19, 20, 18, 19, 31, 3, 24, 0,
     0, 50, 61, 43
};
int yychar;
int yylval;
int yynerrs;
int yyparse (void);
int
yyparse()
    
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register int *yyvsp;
  int yyerrstatus;
  int yychar1 = 0;
  short yyssa[200];
  int yyvsa[200];
  short *yyss = yyssa;
  int *yyvs = yyvsa;
  int yystacksize = 200;
  int yyfree_stacks = 0;
  int yyval;
  int yylen;
  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = -2;
  yyssp = yyss - 1;
  yyvsp = yyvs;
yynewstate:
  *++yyssp = yystate;
  if (yyssp >= yyss + yystacksize - 1)
    {
      int *yyvs1 = yyvs;
      short *yyss1 = yyss;
      int size = yyssp - yyss + 1;
      if (yystacksize >= 10000)
 {
   yyerror("parser stack overflow");
   if (yyfree_stacks)
     {
       free (yyss);
       free (yyvs);
     }
   return 2;
 }
      yystacksize *= 2;
      if (yystacksize > 10000)
 yystacksize = 10000;
      yyss = (short *) __builtin_alloca (yystacksize * sizeof (*yyssp));
      __builtin_memcpy((char *)yyss,(char *)yyss1,size * (unsigned int) sizeof (*yyssp));
      yyvs = (int *) __builtin_alloca (yystacksize * sizeof (*yyvsp));
      __builtin_memcpy((char *)yyvs,(char *)yyvs1,size * (unsigned int) sizeof (*yyvsp));
      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
      if (yyssp >= yyss + yystacksize - 1)
 goto yyabortlab;
    }
  goto yybackup;
 yybackup:
  yyn = yypact[yystate];
  if (yyn == -32768)
    goto yydefault;
  if (yychar == -2)
    {
      yychar = yylex();
    }
  if (yychar <= 0)
    {
      yychar1 = 0;
      yychar = 0;
    }
  else
    {
      yychar1 = ((unsigned)(yychar) <= 265 ? yytranslate[yychar] : 53);
    }
  yyn += yychar1;
  if (yyn < 0 || yyn > 84 || yycheck[yyn] != yychar1)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == -32768)
 goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;
  if (yyn == 85)
    goto yyacceptlab;
  if (yychar != 0)
    yychar = -2;
  *++yyvsp = yylval;
  if (yyerrstatus) yyerrstatus--;
  yystate = yyn;
  goto yynewstate;
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen];
  switch (yyn) {
case 1:
{
   int def_rule;
   pat = cclinit();
   cclnegate( pat );
   def_rule = mkstate( -pat );
   default_rule = num_rules;
   finish_rule( def_rule, 0, 0, 0 );
   for ( i = 1; i <= lastsc; ++i )
    scset[i] = mkbranch( scset[i], def_rule );
   if ( spprdflt )
    add_action(
    "YY_FATAL_ERROR( \"flex scanner jammed\" )" );
   else
    add_action( "ECHO" );
   add_action( ";\n\tYY_BREAK\n" );
   ;
    break;}
case 2:
{
   scinstal( "INITIAL", 0 );
   actvp = 0;
   ;
    break;}
case 5:
{ synerr( "unknown error processing section 1" ); ;
    break;}
case 6:
{
   active_ss = (int *) allocate_array( lastsc + 1, sizeof( int ) );
   for ( i = 1; i <= lastsc; ++i )
    active_ss[i] = 0;
   ;
    break;}
case 7:
{ xcluflg = 0; ;
    break;}
case 8:
{ xcluflg = 1; ;
    break;}
case 9:
{ scinstal( nmstr, xcluflg ); ;
    break;}
case 10:
{ scinstal( nmstr, xcluflg ); ;
    break;}
case 11:
{ synerr( "bad start condition list" ); ;
    break;}
case 14:
{
   trlcontxt = variable_trail_rule = varlength = 0;
   trailcnt = headcnt = rulelen = 0;
   current_state_type = 0x1;
   previous_continued_action = continued_action;
   new_rule();
   ;
    break;}
case 15:
{
   pat = yyvsp[0];
   finish_rule( pat, variable_trail_rule,
    headcnt, trailcnt );
   for ( i = 1; i <= actvp; ++i )
    scbol[actvsc[i]] =
     mkbranch( scbol[actvsc[i]], pat );
   if ( ! bol_needed )
    {
    bol_needed = 1;
    if ( performance_report > 1 )
     pinpoint_message(
   "'^' operator results in sub-optimal performance" );
    }
   ;
    break;}
case 16:
{
   pat = yyvsp[0];
   finish_rule( pat, variable_trail_rule,
    headcnt, trailcnt );
   for ( i = 1; i <= actvp; ++i )
    scset[actvsc[i]] =
     mkbranch( scset[actvsc[i]], pat );
   ;
    break;}
case 17:
{
   pat = yyvsp[0];
   finish_rule( pat, variable_trail_rule,
    headcnt, trailcnt );
   for ( i = 1; i <= lastsc; ++i )
    if ( ! scxclu[i] )
     scbol[i] = mkbranch( scbol[i], pat );
   if ( ! bol_needed )
    {
    bol_needed = 1;
    if ( performance_report > 1 )
     pinpoint_message(
   "'^' operator results in sub-optimal performance" );
    }
   ;
    break;}
case 18:
{
   pat = yyvsp[0];
   finish_rule( pat, variable_trail_rule,
    headcnt, trailcnt );
   for ( i = 1; i <= lastsc; ++i )
    if ( ! scxclu[i] )
     scset[i] = mkbranch( scset[i], pat );
   ;
    break;}
case 19:
{ build_eof_action(); ;
    break;}
case 20:
{
   actvp = 0;
   for ( i = 1; i <= lastsc; ++i )
    if ( ! sceof[i] )
     actvsc[++actvp] = i;
   if ( actvp == 0 )
    warn(
   "all start conditions already have <<EOF>> rules" );
   else
    build_eof_action();
   ;
    break;}
case 21:
{ synerr( "unrecognized rule" ); ;
    break;}
case 23:
{
   actvp = 0;
   for ( i = 1; i <= lastsc; ++i )
    actvsc[++actvp] = i;
   ;
    break;}
case 25:
{ actvp = 0; ;
    break;}
case 27:
{ synerr( "bad start condition list" ); ;
    break;}
case 28:
{
   if ( (scnum = sclookup( nmstr )) == 0 )
    format_pinpoint_message(
     "undeclared start condition %s",
     nmstr );
   else
    {
    if ( ++actvp >= current_max_scs )
     pinpoint_message(
    "too many start conditions in <> construct!" );
    else
     actvsc[actvp] = scnum;
    }
   ;
    break;}
case 29:
{
   if ( transchar[lastst[yyvsp[0]]] != (256 + 1) )
    yyvsp[0] = link_machines( yyvsp[0],
      mkstate( (256 + 1) ) );
   mark_beginning_as_normal( yyvsp[0] );
   current_state_type = 0x1;
   if ( previous_continued_action )
    {
    if ( ! varlength || headcnt != 0 )
     warn(
  "trailing context made variable due to preceding '|' action" );
    varlength = 1;
    headcnt = 0;
    }
   if ( lex_compat || (varlength && headcnt == 0) )
    {
    add_accept( yyvsp[-1],
     num_rules | 0x4000 );
    variable_trail_rule = 1;
    }
   else
    trailcnt = rulelen;
   yyval = link_machines( yyvsp[-1], yyvsp[0] );
   ;
    break;}
case 30:
{ synerr( "trailing context used twice" ); ;
    break;}
case 31:
{
   headcnt = 0;
   trailcnt = 1;
   rulelen = 1;
   varlength = 0;
   current_state_type = 0x2;
   if ( trlcontxt )
    {
    synerr( "trailing context used twice" );
    yyval = mkstate( (256 + 1) );
    }
   else if ( previous_continued_action )
    {
    warn(
  "trailing context made variable due to preceding '|' action" );
    varlength = 1;
    }
   if ( lex_compat || varlength )
    {
    add_accept( yyvsp[-1],
     num_rules | 0x4000 );
    variable_trail_rule = 1;
    }
   trlcontxt = 1;
   eps = mkstate( (256 + 1) );
   yyval = link_machines( yyvsp[-1],
    link_machines( eps, mkstate( '\n' ) ) );
   ;
    break;}
case 32:
{
   yyval = yyvsp[0];
   if ( trlcontxt )
    {
    if ( lex_compat || (varlength && headcnt == 0) )
     variable_trail_rule = 1;
    else
     trailcnt = rulelen;
    }
   ;
    break;}
case 33:
{
   varlength = 1;
   yyval = mkor( yyvsp[-2], yyvsp[0] );
   ;
    break;}
case 34:
{ yyval = yyvsp[0]; ;
    break;}
case 35:
{
   if ( trlcontxt )
    synerr( "trailing context used twice" );
   else
    trlcontxt = 1;
   if ( varlength )
    varlength = 0;
   else
    headcnt = rulelen;
   rulelen = 0;
   current_state_type = 0x2;
   yyval = yyvsp[-1];
   ;
    break;}
case 36:
{
   yyval = link_machines( yyvsp[-1], yyvsp[0] );
   ;
    break;}
case 37:
{ yyval = yyvsp[0]; ;
    break;}
case 38:
{
   varlength = 1;
   yyval = mkclos( yyvsp[-1] );
   ;
    break;}
case 39:
{
   varlength = 1;
   yyval = mkposcl( yyvsp[-1] );
   ;
    break;}
case 40:
{
   varlength = 1;
   yyval = mkopt( yyvsp[-1] );
   ;
    break;}
case 41:
{
   varlength = 1;
   if ( yyvsp[-3] > yyvsp[-1] || yyvsp[-3] < 0 )
    {
    synerr( "bad iteration values" );
    yyval = yyvsp[-5];
    }
   else
    {
    if ( yyvsp[-3] == 0 )
     {
     if ( yyvsp[-1] <= 0 )
      {
      synerr(
      "bad iteration values" );
      yyval = yyvsp[-5];
      }
     else
      yyval = mkopt(
       mkrep( yyvsp[-5], 1, yyvsp[-1] ) );
     }
    else
     yyval = mkrep( yyvsp[-5], yyvsp[-3], yyvsp[-1] );
    }
   ;
    break;}
case 42:
{
   varlength = 1;
   if ( yyvsp[-2] <= 0 )
    {
    synerr( "iteration value must be positive" );
    yyval = yyvsp[-4];
    }
   else
    yyval = mkrep( yyvsp[-4], yyvsp[-2], -1 );
   ;
    break;}
case 43:
{
   varlength = 1;
   if ( yyvsp[-1] <= 0 )
    {
    synerr( "iteration value must be positive" );
    yyval = yyvsp[-3];
    }
   else
    yyval = link_machines( yyvsp[-3],
      copysingl( yyvsp[-3], yyvsp[-1] - 1 ) );
   ;
    break;}
case 44:
{
   if ( ! madeany )
    {
    anyccl = cclinit();
    ccladd( anyccl, '\n' );
    cclnegate( anyccl );
    if ( useecs )
     mkeccl( ccltbl + cclmap[anyccl],
      ccllen[anyccl], nextecm,
      ecgroup, csize, csize );
    madeany = 1;
    }
   ++rulelen;
   yyval = mkstate( -anyccl );
   ;
    break;}
case 45:
{
   if ( ! cclsorted )
    cshell( ccltbl + cclmap[yyvsp[0]], ccllen[yyvsp[0]], 1 );
   if ( useecs )
    mkeccl( ccltbl + cclmap[yyvsp[0]], ccllen[yyvsp[0]],
     nextecm, ecgroup, csize, csize );
   ++rulelen;
   yyval = mkstate( -yyvsp[0] );
   ;
    break;}
case 46:
{
   ++rulelen;
   yyval = mkstate( -yyvsp[0] );
   ;
    break;}
case 47:
{ yyval = yyvsp[-1]; ;
    break;}
case 48:
{ yyval = yyvsp[-1]; ;
    break;}
case 49:
{
   ++rulelen;
   if ( caseins && yyvsp[0] >= 'A' && yyvsp[0] <= 'Z' )
    yyvsp[0] = clower( yyvsp[0] );
   yyval = mkstate( yyvsp[0] );
   ;
    break;}
case 50:
{ yyval = yyvsp[-1]; ;
    break;}
case 51:
{
   cclnegate( yyvsp[-1] );
   yyval = yyvsp[-1];
   ;
    break;}
case 52:
{
   if ( caseins )
    {
    if ( yyvsp[-2] >= 'A' && yyvsp[-2] <= 'Z' )
     yyvsp[-2] = clower( yyvsp[-2] );
    if ( yyvsp[0] >= 'A' && yyvsp[0] <= 'Z' )
     yyvsp[0] = clower( yyvsp[0] );
    }
   if ( yyvsp[-2] > yyvsp[0] )
    synerr( "negative range in character class" );
   else
    {
    for ( i = yyvsp[-2]; i <= yyvsp[0]; ++i )
     ccladd( yyvsp[-3], i );
    cclsorted = cclsorted && (yyvsp[-2] > lastchar);
    lastchar = yyvsp[0];
    }
   yyval = yyvsp[-3];
   ;
    break;}
case 53:
{
   if ( caseins && yyvsp[0] >= 'A' && yyvsp[0] <= 'Z' )
    yyvsp[0] = clower( yyvsp[0] );
   ccladd( yyvsp[-1], yyvsp[0] );
   cclsorted = cclsorted && (yyvsp[0] > lastchar);
   lastchar = yyvsp[0];
   yyval = yyvsp[-1];
   ;
    break;}
case 54:
{
   cclsorted = 1;
   lastchar = 0;
   yyval = cclinit();
   ;
    break;}
case 55:
{
   if ( caseins && yyvsp[0] >= 'A' && yyvsp[0] <= 'Z' )
    yyvsp[0] = clower( yyvsp[0] );
   ++rulelen;
   yyval = link_machines( yyvsp[-1], mkstate( yyvsp[0] ) );
   ;
    break;}
case 56:
{ yyval = mkstate( (256 + 1) ); ;
    break;}
}
  yyvsp -= yylen;
  yyssp -= yylen;
  *++yyvsp = yyval;
  yyn = yyr1[yyn];
  yystate = yypgoto[yyn - 32] + *yyssp;
  if (yystate >= 0 && yystate <= 84 && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - 32];
  goto yynewstate;
yyerrlab:
  if (! yyerrstatus)
    {
      ++yynerrs;
 yyerror("parse error");
    }
  goto yyerrlab1;
yyerrlab1:
  if (yyerrstatus == 3)
    {
      if (yychar == 0)
 goto yyabortlab;
      yychar = -2;
    }
  yyerrstatus = 3;
  goto yyerrhandle;
yyerrdefault:
yyerrpop:
  if (yyssp == yyss) goto yyabortlab;
  yyvsp--;
  yystate = *--yyssp;
yyerrhandle:
  yyn = yypact[yystate];
  if (yyn == -32768)
    goto yyerrdefault;
  yyn += 1;
  if (yyn < 0 || yyn > 84 || yycheck[yyn] != 1)
    goto yyerrdefault;
  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == -32768)
 goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;
  if (yyn == 85)
    goto yyacceptlab;
  *++yyvsp = yylval;
  yystate = yyn;
  goto yynewstate;
 yyacceptlab:
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
    }
  return 0;
 yyabortlab:
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
    }
  return 1;
}
void build_eof_action()
 {
 register int i;
 char action_text[2048];
 for ( i = 1; i <= actvp; ++i )
  {
  if ( sceof[actvsc[i]] )
   format_pinpoint_message(
    "multiple <<EOF>> rules for start condition %s",
    scname[actvsc[i]] );
  else
   {
   sceof[actvsc[i]] = 1;
   sprintf( action_text, "case YY_STATE_EOF(%s):\n",
   scname[actvsc[i]] );
   add_action( action_text );
   }
  }
 line_directive_out( (FILE *) 0 );
 --num_rules;
 ++num_eof_rules;
 }
void format_synerr( msg, arg )
char msg[], arg[];
 {
 char errmsg[2048];
 (void) sprintf( errmsg, msg, arg );
 synerr( errmsg );
 }
void synerr( str )
char str[];
 {
 syntaxerror = 1;
 pinpoint_message( str );
 }
void warn( str )
char str[];
 {
 line_warning( str, linenum );
 }
void format_pinpoint_message( msg, arg )
char msg[], arg[];
 {
 char errmsg[2048];
 (void) sprintf( errmsg, msg, arg );
 pinpoint_message( errmsg );
 }
void pinpoint_message( str )
char str[];
 {
 line_pinpoint( str, linenum );
 }
void line_warning( str, line )
char str[];
int line;
 {
 char warning[2048];
 if ( ! nowarn )
  {
  sprintf( warning, "warning, %s", str );
  line_pinpoint( warning, line );
  }
 }
void line_pinpoint( str, line )
char str[];
int line;
 {
 fprintf( err, "\"%s\", line %d: %s\n", infilename, line, str );
 }
void yyerror( msg )
char msg[];
 {
 }
typedef struct yy_buffer_state *YY_BUFFER_STATE;
extern int yyleng;
extern FILE *yyin, *yyout;
 extern int yywrap ( void );
struct yy_buffer_state
 {
 FILE *yy_input_file;
 char *yy_ch_buf;
 char *yy_buf_pos;
 int yy_buf_size;
 int yy_n_chars;
 int yy_is_interactive;
 int yy_fill_buffer;
 int yy_buffer_status;
 };
static YY_BUFFER_STATE yy_current_buffer = 0;
static char yy_hold_char;
static int yy_n_chars;
int yyleng;
static char *yy_c_buf_p = (char *) 0;
static int yy_init = 1;
static int yy_start = 0;
static int yy_did_buffer_switch_on_eof;
static void yyunput ( int c, char *buf_ptr );
void yyrestart ( FILE *input_file );
void yy_switch_to_buffer ( YY_BUFFER_STATE new_buffer );
void yy_load_buffer_state ( void );
YY_BUFFER_STATE yy_create_buffer ( FILE *file, int size );
void yy_delete_buffer ( YY_BUFFER_STATE b );
void yy_init_buffer ( YY_BUFFER_STATE b, FILE *file );
static int yy_start_stack_ptr = 0;
static int yy_start_stack_depth = 0;
static int *yy_start_stack = 0;
static void yy_push_state ( int new_state );
static void yy_pop_state ( void );
static int yy_top_state ( void );
static void *yy_flex_alloc ( unsigned int );
static void *yy_flex_realloc ( void *, unsigned int );
static void yy_flex_free ( void * );
typedef unsigned char YY_CHAR;
typedef int yy_state_type;
FILE *yyin = (FILE *) 0, *yyout = (FILE *) 0;
extern char *yytext;
static int input ( void );
static yy_state_type yy_get_previous_state ( void );
static yy_state_type yy_try_NUL_trans ( yy_state_type current_state );
static int yy_get_next_buffer ( void );
static void yy_fatal_error ( const char msg[] );
static const short int yy_accept[408] =
    { 0,
        0, 0, 0, 0, 41, 41, 110, 110, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 113, 111, 6, 17, 111, 15, 1, 16,
      111, 111, 111, 14, 60, 53, 54, 60, 47, 60,
       59, 60, 60, 60, 60, 44, 43, 60, 60, 45,
       46, 41, 42, 41, 40, 39, 40, 40, 110, 110,
       26, 27, 26, 26, 26, 26, 26, 26, 29, 28,
       30, 29, 65, 61, 62, 64, 66, 80, 81, 80,
       78, 77, 79, 67, 69, 67, 68, 67, 72, 72,
       72, 74, 76, 74, 74, 74, 75, 92, 97, 92,
       96, 98, 98, 93, 93, 93, 90, 91, 111, 31,
      111, 83, 111, 82, 20, 22, 20, 21, 101, 102,
      101, 100, 103, 105, 103, 106, 107, 88, 88, 89,
       88, 88, 88, 88, 88, 88, 36, 33, 32, 36,
       36, 36, 88, 6, 17, 0, 17, 15, 1, 16,
        0, 16, 13, 7, 0, 0, 0, 3, 0, 4,
        0, 2, 14, 53, 54, 0, 0, 0, 54, 50,
       50, 0, 0, 57, 0, 108, 108, 108, 49, 48,
       49, 44, 43, 0, 43, 56, 44, 41, 42, 40,
       39, 39, 37, 38, 110, 110, 26, 27, 26, 26,
       26, 26, 29, 28, 30, 63, 64, 81, 77, 69,
      109, 109, 109, 70, 71, 76, 73, 92, 97, 0,
       95, 0, 94, 93, 93, 93, 0, 31, 0, 31,
       31, 83, 20, 22, 18, 101, 102, 101, 102, 102,
       99, 103, 105, 104, 88, 88, 88, 89, 85, 88,
       88, 88, 36, 33, 32, 36, 36, 84, 13, 7,
        0, 12, 0, 0, 0, 0, 3, 0, 0, 4,
        0, 5, 0, 51, 0, 52, 0, 0, 57, 0,
       57, 57, 108, 108, 49, 49, 58, 56, 37, 38,
       26, 26, 26, 23, 26, 0, 109, 109, 93, 93,
        0, 19, 0, 85, 85, 88, 88, 36, 36, 12,
        0, 0, 0, 3, 0, 0, 4, 5, 5, 52,
       52, 0, 57, 57, 57, 57, 108, 26, 26, 23,
       23, 0, 109, 93, 93, 19, 19, 88, 88, 36,
       36, 0, 0, 0, 10, 0, 57, 57, 57, 57,
       26, 26, 93, 93, 88, 88, 36, 36, 0, 0,
        0, 0, 57, 57, 24, 25, 86, 87, 86, 87,
       34, 35, 0, 9, 0, 0, 11, 55, 9, 9,
        0, 0, 8, 0, 8, 8, 0
    } ;
static const int yy_ec[256] =
    { 0,
        1, 1, 1, 1, 1, 1, 1, 1, 2, 3,
        1, 1, 4, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 2, 1, 5, 1, 6, 7, 1, 8, 9,
        9, 10, 9, 11, 12, 9, 13, 14, 14, 14,
       14, 14, 14, 14, 14, 14, 14, 1, 1, 15,
        1, 16, 9, 1, 22, 23, 24, 25, 26, 27,
       21, 21, 28, 29, 30, 21, 31, 32, 33, 34,
       21, 35, 36, 37, 38, 21, 21, 39, 40, 21,
       17, 18, 19, 20, 21, 1, 22, 23, 24, 25,
       26, 27, 21, 21, 28, 29, 30, 21, 31, 32,
       33, 34, 21, 35, 36, 37, 38, 21, 21, 39,
       40, 21, 41, 42, 43, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1
    } ;
static const int yy_meta[44] =
    { 0,
        1, 2, 3, 1, 4, 1, 1, 5, 1, 6,
        1, 7, 5, 8, 1, 1, 1, 9, 10, 1,
       11, 12, 12, 12, 12, 12, 12, 11, 11, 11,
       11, 11, 11, 11, 11, 11, 13, 11, 11, 11,
        5, 1, 14
    } ;
static const short int yy_base[470] =
    { 0,
        0, 43, 85, 126, 89, 102, 1611, 1610, 168, 1605,
      108, 111, 211, 0, 1591, 1590, 252, 254, 116, 119,
       98, 122, 144, 146, 297, 0, 93, 104, 338, 340,
      149, 151, 257, 266, 268, 274, 383, 0, 425, 428,
     1596, 1595, 1607, 1615, 278, 1602, 1602, 0, 281, 1600,
     1600, 462, 1592, 0, 1615, 431, 1597, 1597, 1615, 285,
     1615, 1584, 1580, 331, 503, 437, 1593, 1593, 110, 1580,
     1615, 0, 1590, 1590, 0, 1590, 1588, 221, 1587, 1615,
        0, 1585, 1585, 1615, 0, 1561, 1546, 1511, 0, 1551,
     1543, 1543, 1615, 1615, 1498, 0, 1615, 1615, 1500, 1487,
     1615, 1463, 1615, 1615, 1466, 1460, 1615, 332, 1615, 333,
      126, 1615, 1411, 1398, 0, 334, 1615, 0, 1383, 1383,
     1615, 341, 1371, 0, 1354, 1336, 1615, 1615, 271, 1371,
      287, 1370, 1366, 1615, 0, 1362, 1349, 1331, 290, 1335,
      347, 1325, 0, 1323, 1310, 1615, 0, 0, 350, 1306,
     1287, 1246, 1615, 0, 1249, 1227, 0, 1264, 1261, 1255,
     1225, 1197, 1213, 351, 1213, 1213, 1615, 0, 358, 1198,
     1193, 1615, 0, 0, 443, 361, 447, 0, 342, 0,
      363, 1615, 0, 451, 1191, 1188, 1149, 365, 1615, 1615,
     1185, 1181, 1155, 1135, 423, 1615, 1125, 0, 0, 1615,
      546, 588, 1121, 1108, 1615, 0, 1615, 0, 1615, 0,
        0, 1095, 0, 0, 1088, 1615, 0, 1615, 0, 1061,
     1041, 630, 0, 1069, 1615, 1615, 0, 1615, 838, 1615,
     1615, 837, 0, 1615, 1615, 1615, 1615, 0, 1615, 434,
     1615, 0, 1615, 0, 821, 817, 373, 843, 376, 1615,
      842, 1615, 0, 1615, 463, 467, 834, 471, 1615, 833,
     1615, 0, 1615, 1615, 0, 441, 793, 1615, 673, 0,
      805, 802, 0, 830, 1615, 795, 792, 1615, 0, 0,
      594, 818, 817, 597, 784, 790, 0, 775, 786, 0,
      473, 807, 478, 1615, 486, 806, 590, 776, 790, 588,
      469, 703, 793, 0, 0, 0, 1615, 0, 0, 0,
      780, 772, 0, 800, 800, 730, 788, 0, 775, 767,
      600, 795, 602, 0, 773, 772, 764, 770, 762, 1615,
      610, 772, 751, 0, 740, 745, 0, 1615, 765, 1615,
      764, 740, 488, 803, 601, 817, 1615, 742, 730, 1615,
      760, 760, 1615, 738, 726, 1615, 756, 735, 723, 733,
      721, 714, 716, 726, 1615, 724, 602, 831, 715, 658,
      512, 473, 454, 459, 435, 438, 422, 430, 606, 410,
      357, 342, 338, 278, 0, 0, 0, 0, 0, 0,
        0, 0, 614, 255, 618, 131, 1615, 1615, 1615, 156,
      620, 622, 153, 625, 1615, 95, 1615, 858, 872, 886,
      900, 914, 928, 942, 956, 970, 984, 998, 1012, 1026,
     1040, 1054, 1062, 1075, 1081, 1094, 1108, 1122, 1136, 1150,
     1164, 1178, 1186, 1199, 1207, 1220, 1234, 1248, 1262, 1272,
     1280, 1293, 1307, 1321, 1335, 1349, 1363, 1371, 1384, 1398,
     1412, 1416, 1419, 1432, 1446, 1460, 710, 1474, 1487, 1501,
     1515, 711, 1529, 1537, 1544, 712, 743, 1557, 1571
    } ;
static const short int yy_def[470] =
    { 0,
      407, 407, 408, 408, 409, 410, 411, 411, 407, 9,
      412, 412, 407, 13, 413, 413, 414, 414, 415, 415,
      416, 416, 417, 417, 407, 25, 418, 418, 413, 413,
      419, 419, 420, 420, 421, 421, 407, 37, 422, 422,
       37, 37, 407, 407, 407, 407, 407, 423, 407, 407,
      407, 424, 407, 425, 407, 407, 407, 407, 407, 407,
      407, 407, 426, 427, 407, 407, 407, 407, 407, 407,
      407, 428, 407, 428, 429, 430, 429, 429, 431, 407,
      432, 407, 432, 407, 433, 433, 433, 432, 434, 407,
      407, 434, 407, 407, 407, 435, 407, 407, 407, 407,
      407, 407, 407, 407, 407, 407, 407, 427, 407, 436,
      437, 407, 407, 407, 438, 427, 407, 439, 407, 439,
      407, 440, 407, 441, 441, 441, 407, 407, 442, 407,
      442, 407, 407, 407, 443, 407, 443, 407, 444, 407,
      444, 407, 445, 407, 445, 407, 446, 447, 447, 407,
      447, 447, 407, 448, 448, 448, 449, 407, 407, 449,
      449, 449, 447, 407, 407, 407, 407, 423, 407, 407,
      407, 407, 450, 451, 407, 407, 407, 452, 407, 453,
      454, 407, 425, 407, 407, 407, 407, 455, 407, 407,
      407, 407, 407, 456, 426, 407, 407, 457, 458, 407,
      407, 407, 407, 407, 407, 459, 407, 428, 407, 429,
      430, 430, 460, 461, 431, 407, 432, 407, 433, 433,
      433, 407, 434, 407, 407, 407, 435, 407, 407, 407,
      407, 407, 462, 407, 407, 407, 407, 439, 407, 440,
      407, 440, 407, 441, 441, 441, 442, 407, 442, 407,
      407, 407, 443, 407, 463, 444, 407, 444, 407, 407,
      407, 445, 407, 407, 447, 447, 447, 407, 407, 448,
      448, 448, 449, 407, 407, 449, 449, 407, 450, 451,
      407, 407, 407, 407, 407, 407, 464, 407, 407, 465,
      454, 407, 454, 407, 455, 407, 455, 407, 456, 456,
      456, 456, 407, 466, 458, 201, 407, 459, 460, 461,
      433, 433, 222, 407, 222, 222, 407, 467, 441, 441,
      463, 407, 463, 269, 269, 448, 448, 449, 449, 407,
      407, 407, 407, 464, 407, 407, 465, 407, 407, 407,
      407, 407, 456, 456, 456, 456, 407, 433, 433, 407,
      407, 316, 407, 441, 441, 407, 407, 448, 448, 449,
      449, 407, 407, 407, 407, 407, 456, 456, 456, 456,
      433, 433, 441, 441, 448, 448, 449, 449, 468, 407,
      407, 407, 456, 456, 433, 433, 441, 441, 448, 448,
      449, 449, 468, 407, 468, 407, 407, 407, 407, 407,
      469, 469, 407, 469, 407, 407, 0, 407, 407, 407,
      407, 407, 407, 407, 407, 407, 407, 407, 407, 407,
      407, 407, 407, 407, 407, 407, 407, 407, 407, 407,
      407, 407, 407, 407, 407, 407, 407, 407, 407, 407,
      407, 407, 407, 407, 407, 407, 407, 407, 407, 407,
      407, 407, 407, 407, 407, 407, 407, 407, 407, 407,
      407, 407, 407, 407, 407, 407, 407, 407, 407
    } ;
static const short int yy_nxt[1659] =
    { 0,
       44, 45, 46, 47, 44, 44, 44, 44, 44, 44,
       44, 44, 44, 44, 44, 44, 44, 44, 44, 44,
       48, 48, 48, 48, 48, 48, 48, 48, 48, 48,
       48, 48, 48, 48, 48, 48, 48, 48, 48, 48,
       44, 44, 44, 44, 49, 50, 51, 44, 44, 52,
       44, 44, 44, 44, 44, 53, 44, 44, 44, 44,
       44, 44, 44, 54, 54, 54, 54, 54, 54, 54,
       54, 54, 54, 54, 54, 54, 54, 54, 54, 54,
       54, 54, 54, 44, 44, 44, 56, 57, 58, 59,
       60, 73, 74, 61, 61, 130, 131, 61, 405, 62,
       44, 63, 64, 76, 73, 77, 130, 131, 78, 90,
       91, 92, 90, 91, 92, 110, 206, 111, 105, 106,
      107, 105, 106, 107, 44, 65, 61, 66, 67, 68,
       59, 60, 69, 108, 61, 61, 108, 235, 61, 110,
       70, 111, 63, 64, 235, 71, 113, 114, 113, 114,
      207, 136, 137, 136, 137, 115, 405, 115, 138, 399,
      138, 116, 117, 116, 117, 401, 65, 61, 81, 81,
       82, 83, 81, 81, 81, 81, 81, 84, 81, 81,
       81, 81, 81, 81, 81, 81, 81, 81, 85, 85,
       85, 85, 85, 85, 85, 85, 85, 85, 85, 85,
       85, 85, 86, 85, 85, 85, 85, 87, 81, 81,
       81, 93, 93, 44, 93, 93, 93, 93, 93, 93,
       94, 94, 93, 93, 93, 93, 95, 93, 93, 93,
       93, 96, 96, 96, 96, 96, 96, 96, 96, 96,
       96, 96, 96, 96, 96, 96, 96, 96, 96, 96,
       96, 93, 93, 93, 99, 100, 99, 100, 399, 140,
      141, 213, 101, 214, 101, 102, 142, 102, 140, 141,
      144, 145, 146, 248, 249, 142, 144, 145, 146, 164,
      165, 166, 169, 170, 171, 147, 190, 191, 192, 251,
      249, 147, 257, 258, 103, 300, 103, 118, 118, 119,
      120, 121, 118, 118, 122, 118, 118, 118, 118, 123,
      118, 118, 118, 118, 118, 118, 118, 124, 124, 124,
      124, 124, 124, 124, 124, 124, 124, 124, 124, 124,
      124, 125, 124, 124, 124, 124, 126, 127, 118, 128,
      132, 133, 132, 133, 197, 197, 232, 197, 241, 260,
      258, 266, 164, 165, 166, 300, 267, 398, 242, 169,
      170, 171, 281, 282, 283, 292, 293, 296, 297, 198,
      198, 233, 198, 288, 284, 248, 249, 289, 251, 249,
      134, 397, 134, 148, 149, 150, 151, 148, 148, 152,
      148, 148, 153, 148, 148, 148, 148, 148, 148, 148,
      148, 148, 148, 154, 154, 154, 154, 154, 154, 154,
      154, 154, 154, 154, 154, 154, 154, 155, 154, 154,
      154, 154, 156, 148, 148, 148, 158, 159, 160, 158,
      159, 160, 184, 185, 186, 396, 301, 187, 202, 203,
      204, 241, 266, 187, 281, 282, 283, 267, 281, 282,
      283, 242, 184, 185, 186, 392, 284, 187, 391, 161,
      284, 302, 161, 390, 162, 322, 323, 162, 174, 257,
      258, 389, 188, 260, 258, 292, 293, 285, 188, 286,
      339, 293, 345, 175, 388, 176, 300, 176, 296, 297,
      387, 176, 188, 176, 176, 177, 176, 178, 386, 179,
      180, 367, 181, 199, 199, 300, 199, 199, 199, 199,
      199, 199, 199, 199, 199, 199, 200, 199, 199, 199,
      199, 199, 199, 201, 201, 201, 201, 201, 201, 201,
      201, 201, 201, 201, 201, 201, 201, 201, 201, 201,
      201, 201, 201, 199, 199, 199, 305, 305, 385, 305,
      305, 305, 305, 305, 305, 305, 305, 306, 305, 306,
      305, 305, 305, 305, 305, 305, 306, 306, 306, 306,
      306, 306, 306, 306, 306, 306, 306, 306, 306, 306,
      306, 306, 306, 306, 306, 306, 305, 305, 307, 202,
      203, 204, 341, 297, 187, 281, 282, 283, 331, 282,
      283, 343, 322, 323, 357, 323, 299, 284, 394, 395,
      284, 331, 282, 283, 369, 383, 394, 395, 300, 300,
      400, 395, 403, 404, 403, 404, 344, 406, 404, 188,
      313, 313, 314, 315, 313, 313, 313, 313, 313, 316,
      313, 313, 313, 313, 313, 313, 313, 313, 313, 313,
      316, 316, 316, 316, 316, 316, 316, 316, 316, 316,
      316, 316, 316, 316, 316, 316, 316, 316, 316, 316,
      313, 313, 313, 324, 324, 300, 324, 324, 324, 324,
      324, 324, 325, 324, 324, 324, 324, 324, 324, 324,
      324, 324, 324, 325, 325, 325, 325, 325, 325, 325,
      325, 325, 325, 325, 325, 325, 325, 325, 325, 325,
      325, 325, 325, 324, 324, 324, 346, 304, 318, 347,
      300, 304, 318, 347, 346, 346, 346, 346, 346, 346,
      316, 316, 300, 352, 316, 316, 316, 316, 316, 382,
      316, 316, 316, 316, 316, 316, 316, 316, 316, 316,
      353, 381, 380, 379, 353, 378, 377, 376, 375, 356,
      374, 373, 351, 350, 372, 371, 366, 340, 338, 365,
      316, 316, 316, 325, 325, 364, 325, 325, 325, 325,
      325, 325, 363, 325, 325, 325, 325, 325, 325, 325,
      325, 325, 325, 362, 361, 360, 359, 358, 356, 355,
      354, 231, 351, 350, 349, 348, 196, 300, 342, 340,
      338, 336, 335, 325, 325, 325, 368, 333, 332, 330,
      300, 330, 329, 328, 368, 368, 368, 368, 368, 368,
      370, 274, 327, 326, 300, 269, 259, 259, 370, 370,
      370, 370, 370, 370, 384, 250, 250, 320, 300, 319,
      317, 229, 384, 384, 384, 384, 384, 384, 55, 55,
       55, 55, 55, 55, 55, 55, 55, 55, 55, 55,
       55, 55, 72, 72, 72, 72, 72, 72, 72, 72,
       72, 72, 72, 72, 72, 72, 75, 75, 75, 75,
       75, 75, 75, 75, 75, 75, 75, 75, 75, 75,
       79, 79, 79, 79, 79, 79, 79, 79, 79, 79,
       79, 79, 79, 79, 89, 89, 89, 89, 89, 89,
       89, 89, 89, 89, 89, 89, 89, 89, 44, 44,
       44, 44, 44, 44, 44, 44, 44, 44, 44, 44,
       44, 44, 98, 98, 98, 98, 98, 98, 98, 98,
       98, 98, 98, 98, 98, 98, 104, 104, 104, 104,
      104, 104, 104, 104, 104, 104, 104, 104, 104, 104,
      109, 109, 109, 109, 109, 109, 109, 109, 109, 109,
      109, 109, 109, 109, 112, 112, 112, 112, 112, 112,
      112, 112, 112, 112, 112, 112, 112, 112, 129, 129,
      129, 129, 129, 129, 129, 129, 129, 129, 129, 129,
      129, 129, 135, 135, 135, 135, 135, 135, 135, 135,
      135, 135, 135, 135, 135, 135, 139, 139, 139, 139,
      139, 139, 139, 139, 139, 139, 139, 139, 139, 139,
      143, 143, 143, 143, 143, 143, 143, 143, 143, 143,
      143, 143, 143, 143, 157, 157, 157, 157, 157, 157,
      157, 157, 157, 157, 157, 157, 157, 157, 168, 168,
      224, 312, 168, 168, 168, 173, 173, 173, 173, 173,
      173, 173, 173, 173, 173, 173, 173, 183, 183, 311,
      216, 183, 183, 183, 194, 194, 212, 194, 194, 194,
      194, 194, 194, 194, 194, 194, 194, 194, 196, 196,
      205, 196, 196, 196, 196, 196, 196, 196, 196, 196,
      196, 196, 208, 208, 205, 208, 208, 208, 208, 208,
      208, 208, 208, 208, 208, 208, 210, 210, 303, 210,
      210, 210, 210, 210, 210, 210, 210, 210, 210, 210,
      211, 211, 300, 211, 211, 211, 211, 211, 211, 211,
      211, 211, 211, 211, 215, 215, 215, 215, 215, 215,
      215, 215, 215, 215, 215, 215, 215, 215, 217, 217,
      298, 217, 217, 190, 217, 217, 217, 217, 190, 294,
      189, 217, 219, 219, 189, 172, 219, 219, 219, 223,
      223, 172, 223, 223, 223, 223, 223, 223, 223, 223,
      223, 223, 223, 227, 227, 167, 167, 227, 227, 227,
      231, 231, 278, 231, 231, 231, 231, 231, 231, 231,
      231, 231, 231, 231, 234, 234, 277, 234, 234, 234,
      234, 234, 234, 234, 234, 234, 234, 234, 237, 237,
      276, 237, 237, 237, 237, 237, 237, 275, 237, 237,
      237, 237, 238, 238, 275, 274, 272, 238, 238, 238,
      238, 238, 240, 240, 271, 240, 240, 240, 240, 240,
      240, 240, 240, 240, 240, 240, 244, 244, 269, 268,
      244, 244, 244, 247, 247, 247, 247, 247, 247, 247,
      247, 247, 247, 247, 247, 247, 247, 253, 253, 268,
      253, 253, 263, 253, 253, 253, 253, 253, 253, 253,
      253, 256, 256, 256, 256, 256, 263, 256, 256, 256,
      256, 256, 256, 256, 256, 262, 262, 261, 259, 262,
      262, 262, 262, 255, 262, 262, 262, 262, 262, 264,
      264, 254, 264, 264, 264, 264, 264, 264, 264, 264,
      264, 264, 264, 265, 265, 254, 265, 265, 252, 265,
      265, 265, 265, 252, 250, 246, 265, 270, 270, 245,
      243, 270, 270, 270, 273, 239, 239, 273, 273, 273,
      273, 273, 273, 273, 273, 273, 273, 273, 279, 279,
      236, 279, 279, 279, 279, 279, 279, 279, 279, 279,
      279, 279, 280, 280, 236, 280, 280, 280, 280, 280,
      280, 280, 280, 280, 280, 280, 287, 287, 287, 290,
      290, 290, 291, 291, 291, 291, 291, 291, 291, 291,
      291, 291, 291, 291, 291, 291, 295, 295, 295, 295,
      295, 295, 295, 295, 295, 295, 295, 295, 295, 295,
      299, 299, 230, 299, 299, 299, 299, 299, 299, 230,
      299, 299, 299, 299, 305, 305, 229, 305, 305, 305,
      305, 305, 305, 305, 305, 305, 305, 308, 308, 228,
      308, 308, 308, 308, 308, 308, 308, 308, 308, 308,
      308, 309, 309, 228, 309, 309, 309, 309, 309, 309,
      309, 309, 309, 309, 309, 310, 310, 226, 310, 310,
      310, 310, 310, 310, 310, 310, 310, 310, 310, 321,
      321, 321, 321, 321, 321, 321, 321, 321, 321, 321,
      321, 321, 321, 334, 334, 225, 225, 334, 334, 334,
      337, 337, 224, 222, 337, 337, 337, 393, 393, 393,
      393, 393, 393, 393, 393, 393, 393, 393, 393, 393,
      393, 402, 402, 402, 402, 402, 402, 402, 402, 402,
      402, 402, 402, 402, 402, 221, 220, 218, 218, 216,
      209, 212, 209, 209, 193, 205, 205, 195, 193, 189,
      189, 182, 172, 172, 167, 167, 407, 163, 163, 97,
       97, 88, 80, 80, 43, 407, 407, 407, 407, 407,
      407, 407, 407, 407, 407, 407, 407, 407, 407, 407,
      407, 407, 407, 407, 407, 407, 407, 407, 407, 407,
      407, 407, 407, 407, 407, 407, 407, 407, 407, 407,
      407, 407, 407, 407, 407, 407, 407, 407
    } ;
static const short int yy_chk[1659] =
    { 0,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 3, 3, 3, 3,
        3, 5, 5, 3, 3, 27, 27, 3, 406, 3,
       21, 3, 3, 6, 6, 6, 28, 28, 6, 11,
       11, 11, 12, 12, 12, 21, 69, 21, 19, 19,
       19, 20, 20, 20, 22, 3, 3, 4, 4, 4,
        4, 4, 4, 19, 4, 4, 20, 111, 4, 22,
        4, 22, 4, 4, 111, 4, 23, 23, 24, 24,
       69, 31, 31, 32, 32, 23, 403, 24, 31, 400,
       32, 23, 23, 24, 24, 396, 4, 4, 9, 9,
        9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
        9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
        9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
        9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
        9, 13, 13, 13, 13, 13, 13, 13, 13, 13,
       13, 13, 13, 13, 13, 13, 13, 13, 13, 13,
       13, 13, 13, 13, 13, 13, 13, 13, 13, 13,
       13, 13, 13, 13, 13, 13, 13, 13, 13, 13,
       13, 13, 13, 13, 17, 17, 18, 18, 394, 33,
       33, 78, 17, 78, 18, 17, 33, 18, 34, 34,
       35, 35, 35, 129, 129, 34, 36, 36, 36, 45,
       45, 45, 49, 49, 49, 35, 60, 60, 60, 131,
      131, 36, 139, 139, 17, 384, 18, 25, 25, 25,
       25, 25, 25, 25, 25, 25, 25, 25, 25, 25,
       25, 25, 25, 25, 25, 25, 25, 25, 25, 25,
       25, 25, 25, 25, 25, 25, 25, 25, 25, 25,
       25, 25, 25, 25, 25, 25, 25, 25, 25, 25,
       29, 29, 30, 30, 64, 108, 110, 116, 122, 141,
      141, 149, 164, 164, 164, 383, 149, 382, 122, 169,
      169, 169, 176, 176, 176, 181, 181, 188, 188, 64,
      108, 110, 116, 179, 176, 247, 247, 179, 249, 249,
       29, 381, 30, 37, 37, 37, 37, 37, 37, 37,
       37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
       37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
       37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
       37, 37, 37, 37, 37, 37, 39, 39, 39, 40,
       40, 40, 56, 56, 56, 380, 195, 56, 66, 66,
       66, 240, 266, 66, 175, 175, 175, 266, 177, 177,
      177, 240, 184, 184, 184, 378, 175, 184, 377, 39,
      177, 195, 40, 376, 39, 255, 255, 40, 52, 256,
      256, 375, 56, 258, 258, 291, 291, 175, 66, 177,
      293, 293, 301, 52, 374, 52, 301, 52, 295, 295,
      373, 52, 184, 52, 52, 52, 52, 52, 372, 52,
       52, 343, 52, 65, 65, 343, 65, 65, 65, 65,
       65, 65, 65, 65, 65, 65, 65, 65, 65, 65,
       65, 65, 65, 65, 65, 65, 65, 65, 65, 65,
       65, 65, 65, 65, 65, 65, 65, 65, 65, 65,
       65, 65, 65, 65, 65, 65, 201, 201, 371, 201,
      201, 201, 201, 201, 201, 201, 201, 201, 201, 201,
      201, 201, 201, 201, 201, 201, 201, 201, 201, 201,
      201, 201, 201, 201, 201, 201, 201, 201, 201, 201,
      201, 201, 201, 201, 201, 201, 201, 201, 201, 202,
      202, 202, 297, 297, 202, 281, 281, 281, 284, 284,
      284, 300, 321, 321, 323, 323, 300, 281, 379, 379,
      284, 331, 331, 331, 345, 367, 393, 393, 345, 367,
      395, 395, 401, 401, 402, 402, 300, 404, 404, 202,
      222, 222, 222, 222, 222, 222, 222, 222, 222, 222,
      222, 222, 222, 222, 222, 222, 222, 222, 222, 222,
      222, 222, 222, 222, 222, 222, 222, 222, 222, 222,
      222, 222, 222, 222, 222, 222, 222, 222, 222, 222,
      222, 222, 222, 269, 269, 370, 269, 269, 269, 269,
      269, 269, 269, 269, 269, 269, 269, 269, 269, 269,
      269, 269, 269, 269, 269, 269, 269, 269, 269, 269,
      269, 269, 269, 269, 269, 269, 269, 269, 269, 269,
      269, 269, 269, 269, 269, 269, 302, 457, 462, 466,
      302, 457, 462, 466, 302, 302, 302, 302, 302, 302,
      316, 316, 369, 316, 316, 316, 316, 316, 316, 366,
      316, 316, 316, 316, 316, 316, 316, 316, 316, 316,
      467, 364, 363, 362, 467, 361, 360, 359, 358, 357,
      355, 354, 352, 351, 349, 348, 342, 341, 339, 336,
      316, 316, 316, 325, 325, 335, 325, 325, 325, 325,
      325, 325, 333, 325, 325, 325, 325, 325, 325, 325,
      325, 325, 325, 332, 329, 328, 327, 326, 322, 320,
      319, 317, 315, 314, 312, 311, 303, 299, 298, 296,
      292, 289, 288, 325, 325, 325, 344, 286, 285, 283,
      344, 282, 277, 276, 344, 344, 344, 344, 344, 344,
      346, 274, 272, 271, 346, 267, 260, 257, 346, 346,
      346, 346, 346, 346, 368, 251, 248, 246, 368, 245,
      232, 229, 368, 368, 368, 368, 368, 368, 408, 408,
      408, 408, 408, 408, 408, 408, 408, 408, 408, 408,
      408, 408, 409, 409, 409, 409, 409, 409, 409, 409,
      409, 409, 409, 409, 409, 409, 410, 410, 410, 410,
      410, 410, 410, 410, 410, 410, 410, 410, 410, 410,
      411, 411, 411, 411, 411, 411, 411, 411, 411, 411,
      411, 411, 411, 411, 412, 412, 412, 412, 412, 412,
      412, 412, 412, 412, 412, 412, 412, 412, 413, 413,
      413, 413, 413, 413, 413, 413, 413, 413, 413, 413,
      413, 413, 414, 414, 414, 414, 414, 414, 414, 414,
      414, 414, 414, 414, 414, 414, 415, 415, 415, 415,
      415, 415, 415, 415, 415, 415, 415, 415, 415, 415,
      416, 416, 416, 416, 416, 416, 416, 416, 416, 416,
      416, 416, 416, 416, 417, 417, 417, 417, 417, 417,
      417, 417, 417, 417, 417, 417, 417, 417, 418, 418,
      418, 418, 418, 418, 418, 418, 418, 418, 418, 418,
      418, 418, 419, 419, 419, 419, 419, 419, 419, 419,
      419, 419, 419, 419, 419, 419, 420, 420, 420, 420,
      420, 420, 420, 420, 420, 420, 420, 420, 420, 420,
      421, 421, 421, 421, 421, 421, 421, 421, 421, 421,
      421, 421, 421, 421, 422, 422, 422, 422, 422, 422,
      422, 422, 422, 422, 422, 422, 422, 422, 423, 423,
      224, 221, 423, 423, 423, 424, 424, 424, 424, 424,
      424, 424, 424, 424, 424, 424, 424, 425, 425, 220,
      215, 425, 425, 425, 426, 426, 212, 426, 426, 426,
      426, 426, 426, 426, 426, 426, 426, 426, 427, 427,
      204, 427, 427, 427, 427, 427, 427, 427, 427, 427,
      427, 427, 428, 428, 203, 428, 428, 428, 428, 428,
      428, 428, 428, 428, 428, 428, 429, 429, 197, 429,
      429, 429, 429, 429, 429, 429, 429, 429, 429, 429,
      430, 430, 194, 430, 430, 430, 430, 430, 430, 430,
      430, 430, 430, 430, 431, 431, 431, 431, 431, 431,
      431, 431, 431, 431, 431, 431, 431, 431, 432, 432,
      193, 432, 432, 192, 432, 432, 432, 432, 191, 187,
      186, 432, 433, 433, 185, 171, 433, 433, 433, 434,
      434, 170, 434, 434, 434, 434, 434, 434, 434, 434,
      434, 434, 434, 435, 435, 166, 165, 435, 435, 435,
      436, 436, 163, 436, 436, 436, 436, 436, 436, 436,
      436, 436, 436, 436, 437, 437, 162, 437, 437, 437,
      437, 437, 437, 437, 437, 437, 437, 437, 438, 438,
      161, 438, 438, 438, 438, 438, 438, 160, 438, 438,
      438, 438, 439, 439, 159, 158, 156, 439, 439, 439,
      439, 439, 440, 440, 155, 440, 440, 440, 440, 440,
      440, 440, 440, 440, 440, 440, 441, 441, 152, 151,
      441, 441, 441, 442, 442, 442, 442, 442, 442, 442,
      442, 442, 442, 442, 442, 442, 442, 443, 443, 150,
      443, 443, 145, 443, 443, 443, 443, 443, 443, 443,
      443, 444, 444, 444, 444, 444, 144, 444, 444, 444,
      444, 444, 444, 444, 444, 445, 445, 142, 140, 445,
      445, 445, 445, 138, 445, 445, 445, 445, 445, 446,
      446, 137, 446, 446, 446, 446, 446, 446, 446, 446,
      446, 446, 446, 447, 447, 136, 447, 447, 133, 447,
      447, 447, 447, 132, 130, 126, 447, 448, 448, 125,
      123, 448, 448, 448, 449, 120, 119, 449, 449, 449,
      449, 449, 449, 449, 449, 449, 449, 449, 450, 450,
      114, 450, 450, 450, 450, 450, 450, 450, 450, 450,
      450, 450, 451, 451, 113, 451, 451, 451, 451, 451,
      451, 451, 451, 451, 451, 451, 452, 452, 452, 453,
      453, 453, 454, 454, 454, 454, 454, 454, 454, 454,
      454, 454, 454, 454, 454, 454, 455, 455, 455, 455,
      455, 455, 455, 455, 455, 455, 455, 455, 455, 455,
      456, 456, 106, 456, 456, 456, 456, 456, 456, 105,
      456, 456, 456, 456, 458, 458, 102, 458, 458, 458,
      458, 458, 458, 458, 458, 458, 458, 459, 459, 100,
      459, 459, 459, 459, 459, 459, 459, 459, 459, 459,
      459, 460, 460, 99, 460, 460, 460, 460, 460, 460,
      460, 460, 460, 460, 460, 461, 461, 95, 461, 461,
      461, 461, 461, 461, 461, 461, 461, 461, 461, 463,
      463, 463, 463, 463, 463, 463, 463, 463, 463, 463,
      463, 463, 463, 464, 464, 92, 91, 464, 464, 464,
      465, 465, 90, 88, 465, 465, 465, 468, 468, 468,
      468, 468, 468, 468, 468, 468, 468, 468, 468, 468,
      468, 469, 469, 469, 469, 469, 469, 469, 469, 469,
      469, 469, 469, 469, 469, 87, 86, 83, 82, 79,
       77, 76, 74, 73, 70, 68, 67, 63, 62, 58,
       57, 53, 51, 50, 47, 46, 43, 42, 41, 16,
       15, 10, 8, 7, 407, 407, 407, 407, 407, 407,
      407, 407, 407, 407, 407, 407, 407, 407, 407, 407,
      407, 407, 407, 407, 407, 407, 407, 407, 407, 407,
      407, 407, 407, 407, 407, 407, 407, 407, 407, 407,
      407, 407, 407, 407, 407, 407, 407, 407
    } ;
static yy_state_type yy_last_accepting_state;
static char *yy_last_accepting_cpos;
char *yytext;
int flexscan()
 {
 register yy_state_type yy_current_state;
 register char *yy_cp, *yy_bp;
 register int yy_act;
 static int bracelevel, didadef, indented_code, checking_used;
 int doing_codeblock = 0;
 int i;
 unsigned char nmdef[2048], myesc();
 if ( yy_init )
  {
  if ( ! yy_start )
   yy_start = 1;
  if ( ! yyin )
   yyin = stdin;
  if ( ! yyout )
   yyout = stdout;
  if ( yy_current_buffer )
   yy_init_buffer( yy_current_buffer, yyin );
  else
   yy_current_buffer =
    yy_create_buffer( yyin, 16384 );
  yy_load_buffer_state();
  yy_init = 0;
  }
 while ( 1 )
  {
  yy_cp = yy_c_buf_p;
  *yy_cp = yy_hold_char;
  yy_bp = yy_cp;
  yy_current_state = yy_start;
  if ( yy_bp[-1] == '\n' )
   ++yy_current_state;
yy_match:
  do
   {
   register YY_CHAR yy_c = yy_ec[((unsigned int) (unsigned char) *yy_cp)];
   if ( yy_accept[yy_current_state] )
    {
    yy_last_accepting_state = yy_current_state;
    yy_last_accepting_cpos = yy_cp;
    }
   while ( yy_chk[yy_base[yy_current_state] + yy_c] != yy_current_state )
    {
    yy_current_state = (int) yy_def[yy_current_state];
    if ( yy_current_state >= 408 )
     yy_c = yy_meta[(unsigned int) yy_c];
    }
   yy_current_state = yy_nxt[yy_base[yy_current_state] + (unsigned int) yy_c];
   ++yy_cp;
   }
  while ( yy_base[yy_current_state] != 1615 );
yy_find_action:
  yy_act = yy_accept[yy_current_state];
  yytext = yy_bp; yyleng = yy_cp - yy_bp; yy_hold_char = *yy_cp; *yy_cp = '\0'; yy_c_buf_p = yy_cp;;
do_action:
  switch ( yy_act )
 {
   case 0:
   *yy_cp = yy_hold_char;
   yy_cp = yy_last_accepting_cpos;
   yy_current_state = yy_last_accepting_state;
   goto yy_find_action;
case 1:

indented_code = 1; yy_start = 1 + 2 *(4);
 break;
case 2:

add_action( yytext ); yy_start = 1 + 2 *(15);
 break;
case 3:

return 260;
 break;
case 4:

return 261;
 break;
case 5:

{
   ++linenum;
   line_directive_out( (FILE *) 0 );
   indented_code = 0;
   yy_start = 1 + 2 *(4);
   }
 break;
case 6:

return 262;
 break;
case 7:

{
   sectnum = 2;
   bracelevel = 0;
   mark_defs1();
   line_directive_out( (FILE *) 0 );
   yy_start = 1 + 2 *(2);
   return 259;
   }
 break;
case 8:

{
   if ( lex_compat )
    warn( "%pointer incompatible with -l option" );
   else
    yytext_is_array = 0;
   ++linenum;
   }
 break;
case 9:

{
   if ( C_plus_plus )
    warn( "%array incompatible with -+ option" );
   else
    yytext_is_array = 1;
   ++linenum;
   }
 break;
case 10:

{
   warn( "%used/%unused have been deprecated" );
   checking_used = 1; yy_start = 1 + 2 *(19);
   }
 break;
case 11:

{
   warn( "%used/%unused have been deprecated" );
   checking_used = 2; yy_start = 1 + 2 *(19);
   }
 break;
case 12:

++linenum;
 break;
case 13:

synerr( "unrecognized '%' directive" );
 break;
case 14:

{
   strcpy( nmstr, yytext );
   didadef = 0;
   yy_start = 1 + 2 *(5);
   }
 break;
case 15:

strcpy( nmstr, yytext ); return 263;;
 break;
case 16:

++linenum;
 break;
case 17:

++linenum; return '\n';
 break;
case 18:

add_action( yytext ); yy_start = 1 + 2 *(0);
 break;
case 19:

++linenum; add_action( yytext ); yy_start = 1 + 2 *(0);
 break;
case 20:

add_action( yytext );
 break;
case 21:

add_action( yytext );
 break;
case 22:

++linenum; add_action( yytext );
 break;
case 23:

++linenum; yy_start = 1 + 2 *(0);
 break;
case 24:

add_action( yytext ); if ( all_upper( yytext ) ) reject = 1;;
 break;
case 25:

add_action( yytext ); if ( all_lower( yytext ) ) yymore_used = 1;;
 break;
case 26:

add_action( yytext );
 break;
case 27:

{
   ++linenum;
   add_action( yytext );
   if ( indented_code )
    yy_start = 1 + 2 *(0);
   }
 break;
case 28:

 break;
case 29:

{
   strcpy( (char *) nmdef, yytext );
   for ( i = strlen( (char *) nmdef ) - 1;
         i >= 0 && (nmdef[i] == ' ' || nmdef[i] == '\t');
         --i )
    ;
   nmdef[i + 1] = '\0';
   ndinstal( nmstr, nmdef );
   didadef = 1;
   }
 break;
case 30:

{
   if ( ! didadef )
    synerr( "incomplete name definition" );
   yy_start = 1 + 2 *(0);
   ++linenum;
   }
 break;
case 31:

++linenum; yy_start = 1 + 2 *(0); strcpy( nmstr, yytext ); return 263;;
 break;
case 32:

++linenum; yy_start = 1 + 2 *(0);
 break;
case 33:

 break;
case 34:

{
   if ( all_upper( yytext ) )
    reject_really_used = checking_used;
   else
    synerr(
    "unrecognized %used/%unused construct" );
   }
 break;
case 35:

{
   if ( all_lower( yytext ) )
    yymore_really_used = checking_used;
   else
    synerr(
    "unrecognized %used/%unused construct" );
   }
 break;
case 36:

synerr( "unrecognized %used/%unused construct" );
 break;
case 37:

++bracelevel; do { *yy_cp = yy_hold_char; yy_c_buf_p = yy_cp = yy_bp + 2 - 0; yytext = yy_bp; yyleng = yy_cp - yy_bp; yy_hold_char = *yy_cp; *yy_cp = '\0'; yy_c_buf_p = yy_cp;; } while ( 0 );
 break;
case 38:

--bracelevel; do { *yy_cp = yy_hold_char; yy_c_buf_p = yy_cp = yy_bp + 2 - 0; yytext = yy_bp; yyleng = yy_cp - yy_bp; yy_hold_char = *yy_cp; *yy_cp = '\0'; yy_c_buf_p = yy_cp;; } while ( 0 );
 break;
case 39:

add_action( yytext );
 break;
case 40:

{
   if ( bracelevel <= 0 )
    {
    do { *yy_cp = yy_hold_char; yy_c_buf_p = yy_cp = yy_bp + 0 - 0; yytext = yy_bp; yyleng = yy_cp - yy_bp; yy_hold_char = *yy_cp; *yy_cp = '\0'; yy_c_buf_p = yy_cp;; } while ( 0 );
    mark_prolog();
    yy_start = 1 + 2 *(1);
    }
   else
    add_action( yytext );
   }
 break;
case 41:

add_action( yytext );
 break;
case 42:

++linenum; add_action( yytext );
 break;
case (113 + 2 + 1):
{
   mark_prolog();
   sectnum = 0;
   return 0;
   }
 break;
case 43:

++linenum;
 break;
case 44:

{
   indented_code = (yytext[0] != '%');
   doing_codeblock = 1;
   bracelevel = 1;
   if ( indented_code )
    add_action( yytext );
   yy_start = 1 + 2 *(20);
   }
 break;
case 45:

yy_start = 1 + 2 *(6); return '<';
 break;
case 46:

return '^';
 break;
case 47:

yy_start = 1 + 2 *(9); return '"';
 break;
case 48:
*yy_cp = yy_hold_char;
yy_c_buf_p = yy_cp = yy_bp + 1;
yytext = yy_bp; yyleng = yy_cp - yy_bp; yy_hold_char = *yy_cp; *yy_cp = '\0'; yy_c_buf_p = yy_cp;;

yy_start = 1 + 2 *(8); return '{';
 break;
case 49:

yy_start = 1 + 2 *(14);
 break;
case 50:
*yy_cp = yy_hold_char;
yy_c_buf_p = yy_cp = yy_bp + 1;
yytext = yy_bp; yyleng = yy_cp - yy_bp; yy_hold_char = *yy_cp; *yy_cp = '\0'; yy_c_buf_p = yy_cp;;

return '$';
 break;
case 51:

{
   bracelevel = 1;
   yy_start = 1 + 2 *(18);
   return '\n';
   }
 break;
case 52:

continued_action = 1; ++linenum; return '\n';
 break;
case 53:

{
   bracelevel = 0;
   continued_action = 0;
   yy_start = 1 + 2 *(12);
   return '\n';
   }
 break;
case 54:

{
   bracelevel = 0;
   continued_action = 0;
   yy_start = 1 + 2 *(12);
   yyunput( '\n', yytext );
   return '\n';
   }
 break;
case 55:

return 265;
 break;
case 56:

{
   sectnum = 3;
   yy_start = 1 + 2 *(3);
   return 0;
   }
 break;
case 57:

{
   int cclval;
   strcpy( nmstr, yytext );
   if ( (cclval = ccllookup( (unsigned char *) nmstr )) )
    {
    if ( input() != ']' )
     synerr( "bad character class" );
    yylval = cclval;
    ++cclreuse;
    return 264;
    }
   else
    {
    cclinstal( (unsigned char *) nmstr, lastccl + 1 );
    do { *yy_cp = yy_hold_char; yy_c_buf_p = yy_cp = yy_bp + 1 - 0; yytext = yy_bp; yyleng = yy_cp - yy_bp; yy_hold_char = *yy_cp; *yy_cp = '\0'; yy_c_buf_p = yy_cp;; } while ( 0 );
    yy_start = 1 + 2 *(10);
    return '[';
    }
   }
 break;
case 58:

{
   register unsigned char *nmdefptr;
   unsigned char *ndlookup();
   strcpy( nmstr, yytext + 1 );
   nmstr[yyleng - 2] = '\0';
   if ( ! (nmdefptr = ndlookup( nmstr )) )
    format_synerr( "undefined definition {%s}",
      nmstr );
   else
    {
    int len = strlen( (char *) nmdefptr );
    if ( lex_compat || nmdefptr[0] == '^' ||
         (len > 0 && nmdefptr[len - 1] == '$') )
     {
     for ( i = strlen( (char *) nmdefptr ) - 1; i >= 0; --i ) yyunput( ((char *) nmdefptr)[i], yytext );
     if ( nmdefptr[0] == '^' )
      yy_start = 1 + 2 *(7);
     }
    else
     {
     yyunput( ')', yytext );
     for ( i = strlen( (char *) nmdefptr ) - 1; i >= 0; --i ) yyunput( ((char *) nmdefptr)[i], yytext );
     yyunput( '(', yytext );
     }
    }
   }
 break;
case 59:

return (unsigned char) yytext[0];
 break;
case 60:

yylval = (unsigned char) yytext[0]; return 257;;
 break;
case 61:

return (unsigned char) yytext[0];
 break;
case 62:

yy_start = 1 + 2 *(1); return '>';
 break;
case 63:
*yy_cp = yy_hold_char;
yy_c_buf_p = yy_cp = yy_bp + 1;
yytext = yy_bp; yyleng = yy_cp - yy_bp; yy_hold_char = *yy_cp; *yy_cp = '\0'; yy_c_buf_p = yy_cp;;

yy_start = 1 + 2 *(7); return '>';
 break;
case 64:

strcpy( nmstr, yytext ); return 263;;
 break;
case 65:

{
   format_synerr( "bad <start condition>: %s", yytext );
   }
 break;
case 66:

yy_start = 1 + 2 *(1); return '^';
 break;
case 67:

yylval = (unsigned char) yytext[0]; return 257;;
 break;
case 68:

yy_start = 1 + 2 *(1); return '"';
 break;
case 69:

{
   synerr( "missing quote" );
   yy_start = 1 + 2 *(1);
   ++linenum;
   return '"';
   }
 break;
case 70:
*yy_cp = yy_hold_char;
yy_c_buf_p = yy_cp = yy_bp + 1;
yytext = yy_bp; yyleng = yy_cp - yy_bp; yy_hold_char = *yy_cp; *yy_cp = '\0'; yy_c_buf_p = yy_cp;;

yy_start = 1 + 2 *(11); return '^';
 break;
case 71:
*yy_cp = yy_hold_char;
yy_c_buf_p = yy_cp = yy_bp + 1;
yytext = yy_bp; yyleng = yy_cp - yy_bp; yy_hold_char = *yy_cp; *yy_cp = '\0'; yy_c_buf_p = yy_cp;;

return '^';
 break;
case 72:

yy_start = 1 + 2 *(11); yylval = (unsigned char) yytext[0]; return 257;;
 break;
case 73:
*yy_cp = yy_hold_char;
yy_c_buf_p = yy_cp = yy_bp + 1;
yytext = yy_bp; yyleng = yy_cp - yy_bp; yy_hold_char = *yy_cp; *yy_cp = '\0'; yy_c_buf_p = yy_cp;;

return '-';
 break;
case 74:

yylval = (unsigned char) yytext[0]; return 257;;
 break;
case 75:

yy_start = 1 + 2 *(1); return ']';
 break;
case 76:

{
   synerr( "bad character class" );
   yy_start = 1 + 2 *(1);
   return ']';
   }
 break;
case 77:

{
   yylval = myctoi( yytext );
   return 258;
   }
 break;
case 78:

return ',';
 break;
case 79:

yy_start = 1 + 2 *(1); return '}';
 break;
case 80:

{
   synerr( "bad character inside {}'s" );
   yy_start = 1 + 2 *(1);
   return '}';
   }
 break;
case 81:

{
   synerr( "missing }" );
   yy_start = 1 + 2 *(1);
   ++linenum;
   return '}';
   }
 break;
case 82:

synerr( "bad name in {}'s" ); yy_start = 1 + 2 *(1);
 break;
case 83:

synerr( "missing }" ); ++linenum; yy_start = 1 + 2 *(1);
 break;
case 84:

add_action( yytext ); yy_start = 1 + 2 *(16);
 break;
case 85:

bracelevel = 0;
 break;
case 86:

{
   add_action( yytext );
   if ( all_upper( yytext ) ) reject = 1;;
   }
 break;
case 87:

{
   add_action( yytext );
   if ( all_lower( yytext ) ) yymore_used = 1;;
   }
 break;
case 88:

add_action( yytext );
 break;
case 89:

{
   ++linenum;
   add_action( yytext );
   if ( bracelevel == 0 ||
        (doing_codeblock && indented_code) )
    {
    if ( ! doing_codeblock )
     add_action( "\tYY_BREAK\n" );
    doing_codeblock = 0;
    yy_start = 1 + 2 *(1);
    }
   }
 break;
case 90:

add_action( yytext ); ++bracelevel;
 break;
case 91:

add_action( yytext ); --bracelevel;
 break;
case 92:

add_action( yytext );
 break;
case 93:

add_action( yytext );
 break;
case 94:

add_action( yytext ); yy_start = 1 + 2 *(16);
 break;
case 95:

add_action( yytext );
 break;
case 96:

add_action( yytext ); yy_start = 1 + 2 *(17);
 break;
case 97:

{
   ++linenum;
   add_action( yytext );
   if ( bracelevel == 0 )
    {
    add_action( "\tYY_BREAK\n" );
    yy_start = 1 + 2 *(1);
    }
   }
 break;
case 98:

add_action( yytext );
 break;
case 99:

{
   add_action( yytext );
   if ( doing_codeblock )
    yy_start = 1 + 2 *(20);
   else
    yy_start = 1 + 2 *(12);
   }
 break;
case 100:

add_action( yytext );
 break;
case 101:

add_action( yytext );
 break;
case 102:

++linenum; add_action( yytext );
 break;
case 103:

add_action( yytext );
 break;
case 104:

add_action( yytext );
 break;
case 105:

++linenum; add_action( yytext );
 break;
case 106:

add_action( yytext ); yy_start = 1 + 2 *(12);
 break;
case 107:

add_action( yytext );
 break;
case (113 + 12 + 1):
case (113 + 16 + 1):
case (113 + 17 + 1):
{
   synerr( "EOF encountered inside an action" );
   return 0;
   }
 break;
case 108:

{
   yylval = myesc( (unsigned char *) yytext );
   return 257;
   }
 break;
case 109:

{
   yylval = myesc( (unsigned char *) yytext );
   yy_start = 1 + 2 *(11);
   return 257;
   }
 break;
case 110:

(void) fwrite( yytext, yyleng, 1, yyout );
 break;
case (113 + 3 + 1):
sectnum = 0; return 0;
 break;
case 111:

format_synerr( "bad character: %s", yytext );
 break;
case 112:

yy_fatal_error( "flex scanner jammed" );
 break;
case (113 + 0 + 1):
case (113 + 1 + 1):
case (113 + 4 + 1):
case (113 + 5 + 1):
case (113 + 6 + 1):
case (113 + 7 + 1):
case (113 + 8 + 1):
case (113 + 9 + 1):
case (113 + 10 + 1):
case (113 + 11 + 1):
case (113 + 13 + 1):
case (113 + 14 + 1):
case (113 + 15 + 1):
case (113 + 18 + 1):
case (113 + 19 + 1):
case (113 + 20 + 1):
 return 0;
 case 113:
  {
  int yy_amount_of_matched_text = yy_cp - yytext - 1;
  *yy_cp = yy_hold_char;
  if ( yy_current_buffer->yy_buffer_status == 0 )
   {
   yy_n_chars = yy_current_buffer->yy_n_chars;
   yy_current_buffer->yy_input_file = yyin;
   yy_current_buffer->yy_buffer_status = 1;
   }
  if ( yy_c_buf_p <= &yy_current_buffer->yy_ch_buf[yy_n_chars] )
   {
   yy_state_type yy_next_state;
   yy_c_buf_p = yytext + yy_amount_of_matched_text;
   yy_current_state = yy_get_previous_state();
   yy_next_state = yy_try_NUL_trans( yy_current_state );
   yy_bp = yytext + 0;
   if ( yy_next_state )
    {
    yy_cp = ++yy_c_buf_p;
    yy_current_state = yy_next_state;
    goto yy_match;
    }
   else
    {
       yy_cp = yy_c_buf_p;
    goto yy_find_action;
    }
   }
  else switch ( yy_get_next_buffer() )
   {
   case 1:
    {
    yy_did_buffer_switch_on_eof = 0;
    if ( yywrap() )
     {
     yy_c_buf_p = yytext + 0;
     yy_act = (113 + ((yy_start - 1) / 2) + 1);
     goto do_action;
     }
    else
     {
     if ( ! yy_did_buffer_switch_on_eof )
      yyrestart( yyin );
     }
    break;
    }
   case 0:
    yy_c_buf_p =
     yytext + yy_amount_of_matched_text;
    yy_current_state = yy_get_previous_state();
    yy_cp = yy_c_buf_p;
    yy_bp = yytext + 0;
    goto yy_match;
   case 2:
    yy_c_buf_p =
    &yy_current_buffer->yy_ch_buf[yy_n_chars];
    yy_current_state = yy_get_previous_state();
    yy_cp = yy_c_buf_p;
    yy_bp = yytext + 0;
    goto yy_find_action;
   }
  break;
  }
 default:
  yy_fatal_error( "fatal flex scanner internal error--no action found" );
 }
  }
 }
static int yy_get_next_buffer()
 {
 register char *dest = yy_current_buffer->yy_ch_buf;
 register char *source = yytext - 1;
 register int number_to_move, i;
 int ret_val;
 if ( yy_c_buf_p > &yy_current_buffer->yy_ch_buf[yy_n_chars + 1] )
  yy_fatal_error( "fatal flex scanner internal error--end of buffer missed" );
 if ( yy_current_buffer->yy_fill_buffer == 0 )
  {
  if ( yy_c_buf_p - yytext - 0 == 1 )
   {
   return 1;
   }
  else
   {
   return 2;
   }
  }
 number_to_move = yy_c_buf_p - yytext;
 for ( i = 0; i < number_to_move; ++i )
  *(dest++) = *(source++);
 if ( yy_current_buffer->yy_buffer_status == 2 )
  yy_n_chars = 0;
 else
  {
  int num_to_read =
   yy_current_buffer->yy_buf_size - number_to_move - 1;
  while ( num_to_read <= 0 )
   {
   YY_BUFFER_STATE b = yy_current_buffer;
   int yy_c_buf_p_offset = yy_c_buf_p - b->yy_ch_buf;
   b->yy_buf_size *= 2;
   b->yy_ch_buf = (char *)
    yy_flex_realloc( (void *) b->yy_ch_buf,
       b->yy_buf_size );
   if ( ! b->yy_ch_buf )
    yy_fatal_error( "fatal error - scanner input buffer overflow" );
   yy_c_buf_p = &b->yy_ch_buf[yy_c_buf_p_offset];
   num_to_read = yy_current_buffer->yy_buf_size -
      number_to_move - 1;
   }
  if ( num_to_read > 8192 )
   num_to_read = 8192;
  if ( yy_current_buffer->yy_is_interactive ) { int c = _IO_getc (yyin); yy_n_chars = c == (-1) ? 0 : 1; (&yy_current_buffer->yy_ch_buf[number_to_move])[0] = (char) c; } else if ( ((yy_n_chars = fread( (&yy_current_buffer->yy_ch_buf[number_to_move]), 1, num_to_read, yyin )) == 0) && ferror( yyin ) ) yy_fatal_error( "input in flex scanner failed" );;
  }
 if ( yy_n_chars == 0 )
  {
  if ( number_to_move - 0 == 1 )
   {
   ret_val = 1;
   yyrestart( yyin );
   }
  else
   {
   ret_val = 2;
   yy_current_buffer->yy_buffer_status =
    2;
   }
  }
 else
  ret_val = 0;
 yy_n_chars += number_to_move;
 yy_current_buffer->yy_ch_buf[yy_n_chars] = 0;
 yy_current_buffer->yy_ch_buf[yy_n_chars + 1] = 0;
 yytext = &yy_current_buffer->yy_ch_buf[1];
 return ret_val;
 }
static yy_state_type yy_get_previous_state()
 {
 register yy_state_type yy_current_state;
 register char *yy_cp;
 register char *yy_bp = yytext;
 yy_current_state = yy_start;
 if ( yy_bp[-1] == '\n' )
  ++yy_current_state;
 for ( yy_cp = yytext + 0; yy_cp < yy_c_buf_p; ++yy_cp )
  {
  register YY_CHAR yy_c = (*yy_cp ? yy_ec[((unsigned int) (unsigned char) *yy_cp)] : 1);
  if ( yy_accept[yy_current_state] )
   {
   yy_last_accepting_state = yy_current_state;
   yy_last_accepting_cpos = yy_cp;
   }
  while ( yy_chk[yy_base[yy_current_state] + yy_c] != yy_current_state )
   {
   yy_current_state = (int) yy_def[yy_current_state];
   if ( yy_current_state >= 408 )
    yy_c = yy_meta[(unsigned int) yy_c];
   }
  yy_current_state = yy_nxt[yy_base[yy_current_state] + (unsigned int) yy_c];
  }
 return yy_current_state;
 }
static yy_state_type yy_try_NUL_trans( yy_state_type yy_current_state )
 {
 register int yy_is_jam;
 register char *yy_cp = yy_c_buf_p;
 register YY_CHAR yy_c = 1;
 if ( yy_accept[yy_current_state] )
  {
  yy_last_accepting_state = yy_current_state;
  yy_last_accepting_cpos = yy_cp;
  }
 while ( yy_chk[yy_base[yy_current_state] + yy_c] != yy_current_state )
  {
  yy_current_state = (int) yy_def[yy_current_state];
  if ( yy_current_state >= 408 )
   yy_c = yy_meta[(unsigned int) yy_c];
  }
 yy_current_state = yy_nxt[yy_base[yy_current_state] + (unsigned int) yy_c];
 yy_is_jam = (yy_current_state == 407);
 return yy_is_jam ? 0 : yy_current_state;
 }
static void yyunput( int c, register char *yy_bp )
 {
 register char *yy_cp = yy_c_buf_p;
 *yy_cp = yy_hold_char;
 if ( yy_cp < yy_current_buffer->yy_ch_buf + 2 )
  {
  register int number_to_move = yy_n_chars + 2;
  register char *dest = &yy_current_buffer->yy_ch_buf[
     yy_current_buffer->yy_buf_size + 2];
  register char *source =
    &yy_current_buffer->yy_ch_buf[number_to_move];
  while ( source > yy_current_buffer->yy_ch_buf )
   *--dest = *--source;
  yy_cp += dest - source;
  yy_bp += dest - source;
  yy_n_chars = yy_current_buffer->yy_buf_size;
  if ( yy_cp < yy_current_buffer->yy_ch_buf + 2 )
   yy_fatal_error( "flex scanner push-back overflow" );
  }
 if ( yy_cp > yy_bp && yy_cp[-1] == '\n' )
  yy_cp[-2] = '\n';
 *--yy_cp = (char) c;
 yytext = yy_bp; yyleng = yy_cp - yy_bp; yy_hold_char = *yy_cp; *yy_cp = '\0'; yy_c_buf_p = yy_cp;;
 }
static int input()
 {
 int c;
 *yy_c_buf_p = yy_hold_char;
 if ( *yy_c_buf_p == 0 )
  {
  if ( yy_c_buf_p < &yy_current_buffer->yy_ch_buf[yy_n_chars] )
   *yy_c_buf_p = '\0';
  else
   {
   yytext = yy_c_buf_p;
   ++yy_c_buf_p;
   switch ( yy_get_next_buffer() )
    {
    case 1:
     {
     if ( yywrap() )
      {
      yy_c_buf_p =
      yytext + 0;
      return (-1);
      }
     yyrestart( yyin );
     return input();
     }
    case 0:
     yy_c_buf_p = yytext + 0;
     break;
    case 2:
     yy_fatal_error( "unexpected last match in input()" );
    }
   }
  }
 c = *(unsigned char *) yy_c_buf_p;
 *yy_c_buf_p = '\0';
 yy_hold_char = *++yy_c_buf_p;
 return c;
 }
void yyrestart( FILE *input_file )
 {
 if ( ! yy_current_buffer )
  yy_current_buffer = yy_create_buffer( yyin, 16384 );
 yy_init_buffer( yy_current_buffer, input_file );
 yy_load_buffer_state();
 }
void yy_switch_to_buffer( YY_BUFFER_STATE new_buffer )
 {
 if ( yy_current_buffer == new_buffer )
  return;
 if ( yy_current_buffer )
  {
  *yy_c_buf_p = yy_hold_char;
  yy_current_buffer->yy_buf_pos = yy_c_buf_p;
  yy_current_buffer->yy_n_chars = yy_n_chars;
  }
 yy_current_buffer = new_buffer;
 yy_load_buffer_state();
 yy_did_buffer_switch_on_eof = 1;
 }
void yy_load_buffer_state( void )
 {
 yy_n_chars = yy_current_buffer->yy_n_chars;
 yytext = yy_c_buf_p = yy_current_buffer->yy_buf_pos;
 yyin = yy_current_buffer->yy_input_file;
 yy_hold_char = *yy_c_buf_p;
 }
YY_BUFFER_STATE yy_create_buffer( FILE *file, int size )
 {
 YY_BUFFER_STATE b;
 b = (YY_BUFFER_STATE) yy_flex_alloc( sizeof( struct yy_buffer_state ) );
 if ( ! b )
  yy_fatal_error( "out of dynamic memory in yy_create_buffer()" );
 b->yy_buf_size = size;
 b->yy_ch_buf = (char *) yy_flex_alloc( b->yy_buf_size + 2 );
 if ( ! b->yy_ch_buf )
  yy_fatal_error( "out of dynamic memory in yy_create_buffer()" );
 yy_init_buffer( b, file );
 return b;
 }
void yy_delete_buffer( YY_BUFFER_STATE b )
 {
 if ( b == yy_current_buffer )
  yy_current_buffer = (YY_BUFFER_STATE) 0;
 yy_flex_free( (void *) b->yy_ch_buf );
 yy_flex_free( (void *) b );
 }
void yy_init_buffer( YY_BUFFER_STATE b, FILE *file )
 {
 b->yy_input_file = file;
 b->yy_ch_buf[0] = '\n';
 b->yy_n_chars = 1;
 b->yy_ch_buf[1] = 0;
 b->yy_ch_buf[2] = 0;
 b->yy_buf_pos = &b->yy_ch_buf[1];
 b->yy_is_interactive = file ? isatty( fileno(file) ) : 0;
 b->yy_fill_buffer = 1;
 b->yy_buffer_status = 0;
 }
static void yy_push_state( int new_state )
 {
 if ( yy_start_stack_ptr >= yy_start_stack_depth )
  {
  int new_size;
  yy_start_stack_depth += 25;
  new_size = yy_start_stack_depth * sizeof( int );
  if ( ! yy_start_stack )
   yy_start_stack = (int *) yy_flex_alloc( new_size );
  else
   yy_start_stack = (int *) yy_flex_realloc(
     (void *) yy_start_stack, new_size );
  if ( ! yy_start_stack )
   yy_fatal_error( "out of memory expanding start-condition stack" );
  }
 yy_start_stack[yy_start_stack_ptr++] = ((yy_start - 1) / 2);
 yy_start = 1 + 2 *(new_state);
 }
static void yy_pop_state()
 {
 if ( --yy_start_stack_ptr < 0 )
  yy_fatal_error( "start-condition stack underflow" );
 yy_start = 1 + 2 *(yy_start_stack[yy_start_stack_ptr]);
 }
static int yy_top_state()
 {
 return yy_start_stack[yy_start_stack_ptr - 1];
 }
static void yy_fatal_error( const char msg[] )
 {
 (void) fprintf( err, "%s\n", msg );
 exit( 1 );
 }
static void *yy_flex_alloc( unsigned int size )
 {
 return (void *) malloc( size );
 }
static void *yy_flex_realloc( void *ptr, unsigned int size )
 {
 return (void *) realloc( ptr, size );
 }
static void yy_flex_free( void *ptr )
 {
 free( ptr );
 }
int yywrap()
 {
 if ( --num_input_files > 0 )
  {
  set_input_file( *++input_files );
  return 0;
  }
 else
  return 1;
 }
void set_input_file( file )
char *file;
 {
 if ( file )
  {
  infilename = file;
  yyin = fopen( infilename, "r" );
  if ( yyin == ((void *)0) )
   lerrsf( "can't open %s", file );
  }
 else
  {
  yyin = stdin;
  infilename = "<stdin>";
  }
 }
void *flex_alloc( size )
unsigned int size;
 {
 return yy_flex_alloc( size );
 }
void *flex_realloc( ptr, size )
void *ptr;
unsigned int size;
 {
 return yy_flex_realloc( ptr, size );
 }
void flex_free( ptr )
void *ptr;
 {
 yy_flex_free( ptr );
 }
