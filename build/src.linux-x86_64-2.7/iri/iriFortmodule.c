/* File: iriFortmodule.c
 * This file is auto-generated with f2py (version:2).
 * f2py is a Fortran to Python Interface Generator (FPIG), Second Edition,
 * written by Pearu Peterson <pearu@cens.ioc.ee>.
 * See http://cens.ioc.ee/projects/f2py2e/
 * Generation date: Wed Oct 10 18:20:35 2012
 * $Revision:$
 * $Date:$
 * Do not edit this file directly unless you know what you are doing!!!
 */
#ifdef __cplusplus
extern "C" {
#endif

/*********************** See f2py2e/cfuncs.py: includes ***********************/
#include "Python.h"
#include <stdarg.h>
#include "fortranobject.h"
/*need_includes0*/

/**************** See f2py2e/rules.py: mod_rules['modulebody'] ****************/
static PyObject *iriFort_error;
static PyObject *iriFort_module;

/*********************** See f2py2e/cfuncs.py: typedefs ***********************/
/*need_typedefs*/

/****************** See f2py2e/cfuncs.py: typedefs_generated ******************/
/*need_typedefs_generated*/

/********************** See f2py2e/cfuncs.py: cppmacros **********************/
#if defined(PREPEND_FORTRAN)
#if defined(NO_APPEND_FORTRAN)
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) _##F
#else
#define F_FUNC(f,F) _##f
#endif
#else
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) _##F##_
#else
#define F_FUNC(f,F) _##f##_
#endif
#endif
#else
#if defined(NO_APPEND_FORTRAN)
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) F
#else
#define F_FUNC(f,F) f
#endif
#else
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) F##_
#else
#define F_FUNC(f,F) f##_
#endif
#endif
#endif
#if defined(UNDERSCORE_G77)
#define F_FUNC_US(f,F) F_FUNC(f##_,F##_)
#else
#define F_FUNC_US(f,F) F_FUNC(f,F)
#endif

#define rank(var) var ## _Rank
#define shape(var,dim) var ## _Dims[dim]
#define old_rank(var) (((PyArrayObject *)(capi_ ## var ## _tmp))->nd)
#define old_shape(var,dim) (((PyArrayObject *)(capi_ ## var ## _tmp))->dimensions[dim])
#define fshape(var,dim) shape(var,rank(var)-dim-1)
#define len(var) shape(var,0)
#define flen(var) fshape(var,0)
#define old_size(var) PyArray_SIZE((PyArrayObject *)(capi_ ## var ## _tmp))
/* #define index(i) capi_i ## i */
#define slen(var) capi_ ## var ## _len
#define size(var, ...) f2py_size((PyArrayObject *)(capi_ ## var ## _tmp), ## __VA_ARGS__, -1)

#ifdef DEBUGCFUNCS
#define CFUNCSMESS(mess) fprintf(stderr,"debug-capi:"mess);
#define CFUNCSMESSPY(mess,obj) CFUNCSMESS(mess) \
  PyObject_Print((PyObject *)obj,stderr,Py_PRINT_RAW);\
  fprintf(stderr,"\n");
#else
#define CFUNCSMESS(mess)
#define CFUNCSMESSPY(mess,obj)
#endif

#ifndef max
#define max(a,b) ((a > b) ? (a) : (b))
#endif
#ifndef min
#define min(a,b) ((a < b) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a,b) ((a > b) ? (a) : (b))
#endif
#ifndef MIN
#define MIN(a,b) ((a < b) ? (a) : (b))
#endif


/************************ See f2py2e/cfuncs.py: cfuncs ************************/
static int double_from_pyobj(double* v,PyObject *obj,const char *errmess) {
  PyObject* tmp = NULL;
  if (PyFloat_Check(obj)) {
#ifdef __sgi
    *v = PyFloat_AsDouble(obj);
#else
    *v = PyFloat_AS_DOUBLE(obj);
#endif
    return 1;
  }
  tmp = PyNumber_Float(obj);
  if (tmp) {
#ifdef __sgi
    *v = PyFloat_AsDouble(tmp);
#else
    *v = PyFloat_AS_DOUBLE(tmp);
#endif
    Py_DECREF(tmp);
    return 1;
  }
  if (PyComplex_Check(obj))
    tmp = PyObject_GetAttrString(obj,"real");
  else if (PyString_Check(obj) || PyUnicode_Check(obj))
    /*pass*/;
  else if (PySequence_Check(obj))
    tmp = PySequence_GetItem(obj,0);
  if (tmp) {
    PyErr_Clear();
    if (double_from_pyobj(v,tmp,errmess)) {Py_DECREF(tmp); return 1;}
    Py_DECREF(tmp);
  }
  {
    PyObject* err = PyErr_Occurred();
    if (err==NULL) err = iriFort_error;
    PyErr_SetString(err,errmess);
  }
  return 0;
}

int f2py_size(PyArrayObject* var, ...)
{
  npy_int sz = 0;
  npy_int dim;
  npy_int rank;
  va_list argp;
  va_start(argp, var);
  dim = va_arg(argp, npy_int);
  if (dim==-1)
    {
      sz = PyArray_SIZE(var);
    }
  else
    {
      rank = PyArray_NDIM(var);
      if (dim>=1 && dim<=rank)
        sz = PyArray_DIM(var, dim-1);
      else
        fprintf(stderr, "f2py_size: 2nd argument value=%d fails to satisfy 1<=value<=%d. Result will be 0.\n", dim, rank);
    }
  va_end(argp);
  return sz;
}

static int int_from_pyobj(int* v,PyObject *obj,const char *errmess) {
  PyObject* tmp = NULL;
  if (PyInt_Check(obj)) {
    *v = (int)PyInt_AS_LONG(obj);
    return 1;
  }
  tmp = PyNumber_Int(obj);
  if (tmp) {
    *v = PyInt_AS_LONG(tmp);
    Py_DECREF(tmp);
    return 1;
  }
  if (PyComplex_Check(obj))
    tmp = PyObject_GetAttrString(obj,"real");
  else if (PyString_Check(obj) || PyUnicode_Check(obj))
    /*pass*/;
  else if (PySequence_Check(obj))
    tmp = PySequence_GetItem(obj,0);
  if (tmp) {
    PyErr_Clear();
    if (int_from_pyobj(v,tmp,errmess)) {Py_DECREF(tmp); return 1;}
    Py_DECREF(tmp);
  }
  {
    PyObject* err = PyErr_Occurred();
    if (err==NULL) err = iriFort_error;
    PyErr_SetString(err,errmess);
  }
  return 0;
}

static int float_from_pyobj(float* v,PyObject *obj,const char *errmess) {
  double d=0.0;
  if (double_from_pyobj(&d,obj,errmess)) {
    *v = (float)d;
    return 1;
  }
  return 0;
}


/********************* See f2py2e/cfuncs.py: userincludes *********************/
/*need_userincludes*/

/********************* See f2py2e/capi_rules.py: usercode *********************/


/* See f2py2e/rules.py */
extern void F_FUNC_US(iri_sub,IRI_SUB)(int*,int*,float*,float*,int*,int*,float*,float*,float*,float*,float*,float*);
/*eof externroutines*/

/******************** See f2py2e/capi_rules.py: usercode1 ********************/


/******************* See f2py2e/cb_rules.py: buildcallback *******************/
/*need_callbacks*/

/*********************** See f2py2e/rules.py: buildapi ***********************/

/********************************** iri_sub **********************************/
static char doc_f2py_rout_iriFort_iri_sub[] = "\
Function signature:\n\
  outf,oarr = iri_sub(jf,jmag,alati,along,iyyyy,mmdd,dhour,heibeg,heiend,heistp,oarr)\n\
Required arguments:\n"
"  jf : input rank-1 array('i') with bounds (50)\n"
"  jmag : input int\n"
"  alati : input float\n"
"  along : input float\n"
"  iyyyy : input int\n"
"  mmdd : input int\n"
"  dhour : input float\n"
"  heibeg : input float\n"
"  heiend : input float\n"
"  heistp : input float\n"
"  oarr : input rank-1 array('f') with bounds (100)\n"
"Return objects:\n"
"  outf : rank-2 array('f') with bounds (20,1000)\n"
"  oarr : rank-1 array('f') with bounds (100)";
/* extern void F_FUNC_US(iri_sub,IRI_SUB)(int*,int*,float*,float*,int*,int*,float*,float*,float*,float*,float*,float*); */
static PyObject *f2py_rout_iriFort_iri_sub(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(int*,int*,float*,float*,int*,int*,float*,float*,float*,float*,float*,float*)) {
  PyObject * volatile capi_buildvalue = NULL;
  volatile int f2py_success = 1;
/*decl*/

  int *jf = NULL;
  npy_intp jf_Dims[1] = {-1};
  const int jf_Rank = 1;
  PyArrayObject *capi_jf_tmp = NULL;
  int capi_jf_intent = 0;
  PyObject *jf_capi = Py_None;
  int jmag = 0;
  PyObject *jmag_capi = Py_None;
  float alati = 0;
  PyObject *alati_capi = Py_None;
  float along = 0;
  PyObject *along_capi = Py_None;
  int iyyyy = 0;
  PyObject *iyyyy_capi = Py_None;
  int mmdd = 0;
  PyObject *mmdd_capi = Py_None;
  float dhour = 0;
  PyObject *dhour_capi = Py_None;
  float heibeg = 0;
  PyObject *heibeg_capi = Py_None;
  float heiend = 0;
  PyObject *heiend_capi = Py_None;
  float heistp = 0;
  PyObject *heistp_capi = Py_None;
  float *outf = NULL;
  npy_intp outf_Dims[2] = {-1, -1};
  const int outf_Rank = 2;
  PyArrayObject *capi_outf_tmp = NULL;
  int capi_outf_intent = 0;
  float *oarr = NULL;
  npy_intp oarr_Dims[1] = {-1};
  const int oarr_Rank = 1;
  PyArrayObject *capi_oarr_tmp = NULL;
  int capi_oarr_intent = 0;
  PyObject *oarr_capi = Py_None;
  static char *capi_kwlist[] = {"jf","jmag","alati","along","iyyyy","mmdd","dhour","heibeg","heiend","heistp","oarr",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
  if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
    "OOOOOOOOOOO:iriFort.iri_sub",\
    capi_kwlist,&jf_capi,&jmag_capi,&alati_capi,&along_capi,&iyyyy_capi,&mmdd_capi,&dhour_capi,&heibeg_capi,&heiend_capi,&heistp_capi,&oarr_capi))
    return NULL;
/*frompyobj*/
  /* Processing variable mmdd */
    f2py_success = int_from_pyobj(&mmdd,mmdd_capi,"iriFort.iri_sub() 6th argument (mmdd) can't be converted to int");
  if (f2py_success) {
  /* Processing variable jf */
  jf_Dims[0]=50;
  capi_jf_intent |= F2PY_INTENT_IN;
  capi_jf_tmp = array_from_pyobj(PyArray_INT,jf_Dims,jf_Rank,capi_jf_intent,jf_capi);
  if (capi_jf_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(iriFort_error,"failed in converting 1st argument `jf' of iriFort.iri_sub to C/Fortran array" );
  } else {
    jf = (int *)(capi_jf_tmp->data);

  /* Processing variable jmag */
    f2py_success = int_from_pyobj(&jmag,jmag_capi,"iriFort.iri_sub() 2nd argument (jmag) can't be converted to int");
  if (f2py_success) {
  /* Processing variable heistp */
    f2py_success = float_from_pyobj(&heistp,heistp_capi,"iriFort.iri_sub() 10th argument (heistp) can't be converted to float");
  if (f2py_success) {
  /* Processing variable alati */
    f2py_success = float_from_pyobj(&alati,alati_capi,"iriFort.iri_sub() 3rd argument (alati) can't be converted to float");
  if (f2py_success) {
  /* Processing variable iyyyy */
    f2py_success = int_from_pyobj(&iyyyy,iyyyy_capi,"iriFort.iri_sub() 5th argument (iyyyy) can't be converted to int");
  if (f2py_success) {
  /* Processing variable outf */
  outf_Dims[0]=20,outf_Dims[1]=1000;
  capi_outf_intent |= F2PY_INTENT_OUT|F2PY_INTENT_HIDE;
  capi_outf_tmp = array_from_pyobj(PyArray_FLOAT,outf_Dims,outf_Rank,capi_outf_intent,Py_None);
  if (capi_outf_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(iriFort_error,"failed in converting hidden `outf' of iriFort.iri_sub to C/Fortran array" );
  } else {
    outf = (float *)(capi_outf_tmp->data);

  /* Processing variable heiend */
    f2py_success = float_from_pyobj(&heiend,heiend_capi,"iriFort.iri_sub() 9th argument (heiend) can't be converted to float");
  if (f2py_success) {
  /* Processing variable oarr */
  oarr_Dims[0]=100;
  capi_oarr_intent |= F2PY_INTENT_IN|F2PY_INTENT_OUT;
  capi_oarr_tmp = array_from_pyobj(PyArray_FLOAT,oarr_Dims,oarr_Rank,capi_oarr_intent,oarr_capi);
  if (capi_oarr_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(iriFort_error,"failed in converting 11st argument `oarr' of iriFort.iri_sub to C/Fortran array" );
  } else {
    oarr = (float *)(capi_oarr_tmp->data);

  /* Processing variable along */
    f2py_success = float_from_pyobj(&along,along_capi,"iriFort.iri_sub() 4th argument (along) can't be converted to float");
  if (f2py_success) {
  /* Processing variable dhour */
    f2py_success = float_from_pyobj(&dhour,dhour_capi,"iriFort.iri_sub() 7th argument (dhour) can't be converted to float");
  if (f2py_success) {
  /* Processing variable heibeg */
    f2py_success = float_from_pyobj(&heibeg,heibeg_capi,"iriFort.iri_sub() 8th argument (heibeg) can't be converted to float");
  if (f2py_success) {
/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
        (*f2py_func)(jf,&jmag,&alati,&along,&iyyyy,&mmdd,&dhour,&heibeg,&heiend,&heistp,outf,oarr);
if (PyErr_Occurred())
  f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_call_clock();
#endif
/*end of callfortranroutine*/
    if (f2py_success) {
/*pyobjfrom*/
/*end of pyobjfrom*/
    CFUNCSMESS("Building return value.\n");
    capi_buildvalue = Py_BuildValue("NN",capi_outf_tmp,capi_oarr_tmp);
/*closepyobjfrom*/
/*end of closepyobjfrom*/
    } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
  } /*if (f2py_success) of heibeg*/
  /* End of cleaning variable heibeg */
  } /*if (f2py_success) of dhour*/
  /* End of cleaning variable dhour */
  } /*if (f2py_success) of along*/
  /* End of cleaning variable along */
  }  /*if (capi_oarr_tmp == NULL) ... else of oarr*/
  /* End of cleaning variable oarr */
  } /*if (f2py_success) of heiend*/
  /* End of cleaning variable heiend */
  }  /*if (capi_outf_tmp == NULL) ... else of outf*/
  /* End of cleaning variable outf */
  } /*if (f2py_success) of iyyyy*/
  /* End of cleaning variable iyyyy */
  } /*if (f2py_success) of alati*/
  /* End of cleaning variable alati */
  } /*if (f2py_success) of heistp*/
  /* End of cleaning variable heistp */
  } /*if (f2py_success) of jmag*/
  /* End of cleaning variable jmag */
  if((PyObject *)capi_jf_tmp!=jf_capi) {
    Py_XDECREF(capi_jf_tmp); }
  }  /*if (capi_jf_tmp == NULL) ... else of jf*/
  /* End of cleaning variable jf */
  } /*if (f2py_success) of mmdd*/
  /* End of cleaning variable mmdd */
/*end of cleanupfrompyobj*/
  if (capi_buildvalue == NULL) {
/*routdebugfailure*/
  } else {
/*routdebugleave*/
  }
  CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_clock();
#endif
  return capi_buildvalue;
}
/******************************* end of iri_sub *******************************/
/*eof body*/

/******************* See f2py2e/f90mod_rules.py: buildhooks *******************/
/*need_f90modhooks*/

/************** See f2py2e/rules.py: module_rules['modulebody'] **************/

/******************* See f2py2e/common_rules.py: buildhooks *******************/

static FortranDataDef f2py_block7_def[] = {
  {"d1",0,{{-1}},PyArray_FLOAT},
  {"xkk",0,{{-1}},PyArray_FLOAT},
  {"fp30",0,{{-1}},PyArray_FLOAT},
  {"fp3u",0,{{-1}},PyArray_FLOAT},
  {"fp1",0,{{-1}},PyArray_FLOAT},
  {"fp2",0,{{-1}},PyArray_FLOAT},
  {NULL}
};
static void f2py_setup_block7(char *d1,char *xkk,char *fp30,char *fp3u,char *fp1,char *fp2) {
  int i_f2py=0;
  f2py_block7_def[i_f2py++].data = d1;
  f2py_block7_def[i_f2py++].data = xkk;
  f2py_block7_def[i_f2py++].data = fp30;
  f2py_block7_def[i_f2py++].data = fp3u;
  f2py_block7_def[i_f2py++].data = fp1;
  f2py_block7_def[i_f2py++].data = fp2;
}
extern void F_FUNC(f2pyinitblock7,F2PYINITBLOCK7)(void(*)(char*,char*,char*,char*,char*,char*));
static void f2py_init_block7(void) {
  F_FUNC(f2pyinitblock7,F2PYINITBLOCK7)(f2py_setup_block7);
}

static FortranDataDef f2py_block6_def[] = {
  {"hmd",0,{{-1}},PyArray_FLOAT},
  {"nmd",0,{{-1}},PyArray_FLOAT},
  {"hdx",0,{{-1}},PyArray_FLOAT},
  {NULL}
};
static void f2py_setup_block6(char *hmd,char *nmd,char *hdx) {
  int i_f2py=0;
  f2py_block6_def[i_f2py++].data = hmd;
  f2py_block6_def[i_f2py++].data = nmd;
  f2py_block6_def[i_f2py++].data = hdx;
}
extern void F_FUNC(f2pyinitblock6,F2PYINITBLOCK6)(void(*)(char*,char*,char*));
static void f2py_init_block6(void) {
  F_FUNC(f2pyinitblock6,F2PYINITBLOCK6)(f2py_setup_block6);
}

static FortranDataDef f2py_block5_def[] = {
  {"enight",0,{{-1}},PyArray_INT},
  {"e",1,{{4}},PyArray_FLOAT},
  {NULL}
};
static void f2py_setup_block5(char *enight,char *e) {
  int i_f2py=0;
  f2py_block5_def[i_f2py++].data = enight;
  f2py_block5_def[i_f2py++].data = e;
}
extern void F_FUNC(f2pyinitblock5,F2PYINITBLOCK5)(void(*)(char*,char*));
static void f2py_init_block5(void) {
  F_FUNC(f2pyinitblock5,F2PYINITBLOCK5)(f2py_setup_block5);
}

static FortranDataDef f2py_block4_def[] = {
  {"hme",0,{{-1}},PyArray_FLOAT},
  {"nme",0,{{-1}},PyArray_FLOAT},
  {"hef",0,{{-1}},PyArray_FLOAT},
  {NULL}
};
static void f2py_setup_block4(char *hme,char *nme,char *hef) {
  int i_f2py=0;
  f2py_block4_def[i_f2py++].data = hme;
  f2py_block4_def[i_f2py++].data = nme;
  f2py_block4_def[i_f2py++].data = hef;
}
extern void F_FUNC(f2pyinitblock4,F2PYINITBLOCK4)(void(*)(char*,char*,char*));
static void f2py_init_block4(void) {
  F_FUNC(f2pyinitblock4,F2PYINITBLOCK4)(f2py_setup_block4);
}

static FortranDataDef f2py_const_def[] = {
  {"umr",0,{{-1}},PyArray_FLOAT},
  {NULL}
};
static void f2py_setup_const(char *umr) {
  int i_f2py=0;
  f2py_const_def[i_f2py++].data = umr;
}
extern void F_FUNC(f2pyinitconst,F2PYINITCONST)(void(*)(char*));
static void f2py_init_const(void) {
  F_FUNC(f2pyinitconst,F2PYINITCONST)(f2py_setup_const);
}

static FortranDataDef f2py_block2_def[] = {
  {"b0",0,{{-1}},PyArray_FLOAT},
  {"b1",0,{{-1}},PyArray_FLOAT},
  {"c1",0,{{-1}},PyArray_FLOAT},
  {NULL}
};
static void f2py_setup_block2(char *b0,char *b1,char *c1) {
  int i_f2py=0;
  f2py_block2_def[i_f2py++].data = b0;
  f2py_block2_def[i_f2py++].data = b1;
  f2py_block2_def[i_f2py++].data = c1;
}
extern void F_FUNC(f2pyinitblock2,F2PYINITBLOCK2)(void(*)(char*,char*,char*));
static void f2py_init_block2(void) {
  F_FUNC(f2pyinitblock2,F2PYINITBLOCK2)(f2py_setup_block2);
}

static FortranDataDef f2py_block1_def[] = {
  {"hmf2",0,{{-1}},PyArray_FLOAT},
  {"nmf2",0,{{-1}},PyArray_FLOAT},
  {"hmf1",0,{{-1}},PyArray_FLOAT},
  {"f1reg",0,{{-1}},PyArray_INT},
  {NULL}
};
static void f2py_setup_block1(char *hmf2,char *nmf2,char *hmf1,char *f1reg) {
  int i_f2py=0;
  f2py_block1_def[i_f2py++].data = hmf2;
  f2py_block1_def[i_f2py++].data = nmf2;
  f2py_block1_def[i_f2py++].data = hmf1;
  f2py_block1_def[i_f2py++].data = f1reg;
}
extern void F_FUNC(f2pyinitblock1,F2PYINITBLOCK1)(void(*)(char*,char*,char*,char*));
static void f2py_init_block1(void) {
  F_FUNC(f2pyinitblock1,F2PYINITBLOCK1)(f2py_setup_block1);
}

static FortranDataDef f2py_block8_def[] = {
  {"hs",0,{{-1}},PyArray_FLOAT},
  {"tnhs",0,{{-1}},PyArray_FLOAT},
  {"xsm",1,{{4}},PyArray_FLOAT},
  {"mm",1,{{5}},PyArray_FLOAT},
  {"dti",1,{{4}},PyArray_FLOAT},
  {"mxsm",0,{{-1}},PyArray_INT},
  {NULL}
};
static void f2py_setup_block8(char *hs,char *tnhs,char *xsm,char *mm,char *dti,char *mxsm) {
  int i_f2py=0;
  f2py_block8_def[i_f2py++].data = hs;
  f2py_block8_def[i_f2py++].data = tnhs;
  f2py_block8_def[i_f2py++].data = xsm;
  f2py_block8_def[i_f2py++].data = mm;
  f2py_block8_def[i_f2py++].data = dti;
  f2py_block8_def[i_f2py++].data = mxsm;
}
extern void F_FUNC(f2pyinitblock8,F2PYINITBLOCK8)(void(*)(char*,char*,char*,char*,char*,char*));
static void f2py_init_block8(void) {
  F_FUNC(f2pyinitblock8,F2PYINITBLOCK8)(f2py_setup_block8);
}

static FortranDataDef f2py_argexp_def[] = {
  {"argmax",0,{{-1}},PyArray_FLOAT},
  {NULL}
};
static void f2py_setup_argexp(char *argmax) {
  int i_f2py=0;
  f2py_argexp_def[i_f2py++].data = argmax;
}
extern void F_FUNC(f2pyinitargexp,F2PYINITARGEXP)(void(*)(char*));
static void f2py_init_argexp(void) {
  F_FUNC(f2pyinitargexp,F2PYINITARGEXP)(f2py_setup_argexp);
}

static FortranDataDef f2py_iounit_def[] = {
  {"konsol",0,{{-1}},PyArray_INT},
  {NULL}
};
static void f2py_setup_iounit(char *konsol) {
  int i_f2py=0;
  f2py_iounit_def[i_f2py++].data = konsol;
}
extern void F_FUNC(f2pyinitiounit,F2PYINITIOUNIT)(void(*)(char*));
static void f2py_init_iounit(void) {
  F_FUNC(f2pyinitiounit,F2PYINITIOUNIT)(f2py_setup_iounit);
}

static FortranDataDef f2py_blo11_def[] = {
  {"b2top",0,{{-1}},PyArray_FLOAT},
  {"tc3",0,{{-1}},PyArray_FLOAT},
  {"itopn",0,{{-1}},PyArray_INT},
  {"alg10",0,{{-1}},PyArray_FLOAT},
  {"hcor1",0,{{-1}},PyArray_FLOAT},
  {NULL}
};
static void f2py_setup_blo11(char *b2top,char *tc3,char *itopn,char *alg10,char *hcor1) {
  int i_f2py=0;
  f2py_blo11_def[i_f2py++].data = b2top;
  f2py_blo11_def[i_f2py++].data = tc3;
  f2py_blo11_def[i_f2py++].data = itopn;
  f2py_blo11_def[i_f2py++].data = alg10;
  f2py_blo11_def[i_f2py++].data = hcor1;
}
extern void F_FUNC(f2pyinitblo11,F2PYINITBLO11)(void(*)(char*,char*,char*,char*,char*));
static void f2py_init_blo11(void) {
  F_FUNC(f2pyinitblo11,F2PYINITBLO11)(f2py_setup_blo11);
}

static FortranDataDef f2py_blo10_def[] = {
  {"beta",0,{{-1}},PyArray_FLOAT},
  {"eta",0,{{-1}},PyArray_FLOAT},
  {"delta",0,{{-1}},PyArray_FLOAT},
  {"zeta",0,{{-1}},PyArray_FLOAT},
  {NULL}
};
static void f2py_setup_blo10(char *beta,char *eta,char *delta,char *zeta) {
  int i_f2py=0;
  f2py_blo10_def[i_f2py++].data = beta;
  f2py_blo10_def[i_f2py++].data = eta;
  f2py_blo10_def[i_f2py++].data = delta;
  f2py_blo10_def[i_f2py++].data = zeta;
}
extern void F_FUNC(f2pyinitblo10,F2PYINITBLO10)(void(*)(char*,char*,char*,char*));
static void f2py_init_blo10(void) {
  F_FUNC(f2pyinitblo10,F2PYINITBLO10)(f2py_setup_blo10);
}

static FortranDataDef f2py_const1_def[] = {
  {"humr",0,{{-1}},PyArray_FLOAT},
  {"dumr",0,{{-1}},PyArray_FLOAT},
  {NULL}
};
static void f2py_setup_const1(char *humr,char *dumr) {
  int i_f2py=0;
  f2py_const1_def[i_f2py++].data = humr;
  f2py_const1_def[i_f2py++].data = dumr;
}
extern void F_FUNC(f2pyinitconst1,F2PYINITCONST1)(void(*)(char*,char*));
static void f2py_init_const1(void) {
  F_FUNC(f2pyinitconst1,F2PYINITCONST1)(f2py_setup_const1);
}

static FortranDataDef f2py_blote_def[] = {
  {"ahh",1,{{7}},PyArray_FLOAT},
  {"ate1",0,{{-1}},PyArray_FLOAT},
  {"stte",1,{{6}},PyArray_FLOAT},
  {"dte",1,{{5}},PyArray_FLOAT},
  {NULL}
};
static void f2py_setup_blote(char *ahh,char *ate1,char *stte,char *dte) {
  int i_f2py=0;
  f2py_blote_def[i_f2py++].data = ahh;
  f2py_blote_def[i_f2py++].data = ate1;
  f2py_blote_def[i_f2py++].data = stte;
  f2py_blote_def[i_f2py++].data = dte;
}
extern void F_FUNC(f2pyinitblote,F2PYINITBLOTE)(void(*)(char*,char*,char*,char*));
static void f2py_init_blote(void) {
  F_FUNC(f2pyinitblote,F2PYINITBLOTE)(f2py_setup_blote);
}

static FortranDataDef f2py_const2_def[] = {
  {"icalls",0,{{-1}},PyArray_INT},
  {"nmono",0,{{-1}},PyArray_INT},
  {"iyearo",0,{{-1}},PyArray_INT},
  {"idaynro",0,{{-1}},PyArray_INT},
  {"rzino",0,{{-1}},PyArray_INT},
  {"igino",0,{{-1}},PyArray_INT},
  {"ut0",0,{{-1}},PyArray_FLOAT},
  {NULL}
};
static void f2py_setup_const2(char *icalls,char *nmono,char *iyearo,char *idaynro,char *rzino,char *igino,char *ut0) {
  int i_f2py=0;
  f2py_const2_def[i_f2py++].data = icalls;
  f2py_const2_def[i_f2py++].data = nmono;
  f2py_const2_def[i_f2py++].data = iyearo;
  f2py_const2_def[i_f2py++].data = idaynro;
  f2py_const2_def[i_f2py++].data = rzino;
  f2py_const2_def[i_f2py++].data = igino;
  f2py_const2_def[i_f2py++].data = ut0;
}
extern void F_FUNC(f2pyinitconst2,F2PYINITCONST2)(void(*)(char*,char*,char*,char*,char*,char*,char*));
static void f2py_init_const2(void) {
  F_FUNC(f2pyinitconst2,F2PYINITCONST2)(f2py_setup_const2);
}

static FortranDataDef f2py_block3_def[] = {
  {"hz",0,{{-1}},PyArray_FLOAT},
  {"t",0,{{-1}},PyArray_FLOAT},
  {"hst",0,{{-1}},PyArray_FLOAT},
  {NULL}
};
static void f2py_setup_block3(char *hz,char *t,char *hst) {
  int i_f2py=0;
  f2py_block3_def[i_f2py++].data = hz;
  f2py_block3_def[i_f2py++].data = t;
  f2py_block3_def[i_f2py++].data = hst;
}
extern void F_FUNC(f2pyinitblock3,F2PYINITBLOCK3)(void(*)(char*,char*,char*));
static void f2py_init_block3(void) {
  F_FUNC(f2pyinitblock3,F2PYINITBLOCK3)(f2py_setup_block3);
}

static FortranDataDef f2py_qtop_def[] = {
  {"y05",0,{{-1}},PyArray_FLOAT},
  {"h05top",0,{{-1}},PyArray_FLOAT},
  {"qf",0,{{-1}},PyArray_FLOAT},
  {"xnetop",0,{{-1}},PyArray_FLOAT},
  {"xm3000",0,{{-1}},PyArray_FLOAT},
  {"hhalf",0,{{-1}},PyArray_FLOAT},
  {"tau",0,{{-1}},PyArray_FLOAT},
  {NULL}
};
static void f2py_setup_qtop(char *y05,char *h05top,char *qf,char *xnetop,char *xm3000,char *hhalf,char *tau) {
  int i_f2py=0;
  f2py_qtop_def[i_f2py++].data = y05;
  f2py_qtop_def[i_f2py++].data = h05top;
  f2py_qtop_def[i_f2py++].data = qf;
  f2py_qtop_def[i_f2py++].data = xnetop;
  f2py_qtop_def[i_f2py++].data = xm3000;
  f2py_qtop_def[i_f2py++].data = hhalf;
  f2py_qtop_def[i_f2py++].data = tau;
}
extern void F_FUNC(f2pyinitqtop,F2PYINITQTOP)(void(*)(char*,char*,char*,char*,char*,char*,char*));
static void f2py_init_qtop(void) {
  F_FUNC(f2pyinitqtop,F2PYINITQTOP)(f2py_setup_qtop);
}

static FortranDataDef f2py_findrlat_def[] = {
  {"flon",0,{{-1}},PyArray_FLOAT},
  {"ryear",0,{{-1}},PyArray_FLOAT},
  {NULL}
};
static void f2py_setup_findrlat(char *flon,char *ryear) {
  int i_f2py=0;
  f2py_findrlat_def[i_f2py++].data = flon;
  f2py_findrlat_def[i_f2py++].data = ryear;
}
extern void F_FUNC(f2pyinitfindrlat,F2PYINITFINDRLAT)(void(*)(char*,char*));
static void f2py_init_findrlat(void) {
  F_FUNC(f2pyinitfindrlat,F2PYINITFINDRLAT)(f2py_setup_findrlat);
}

/*need_commonhooks*/

/**************************** See f2py2e/rules.py ****************************/

static FortranDataDef f2py_routine_defs[] = {
  {"iri_sub",-1,{{-1}},0,(char *)F_FUNC_US(iri_sub,IRI_SUB),(f2py_init_func)f2py_rout_iriFort_iri_sub,doc_f2py_rout_iriFort_iri_sub},

/*eof routine_defs*/
  {NULL}
};

static PyMethodDef f2py_module_methods[] = {

  {NULL,NULL}
};

#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef moduledef = {
  PyModuleDef_HEAD_INIT,
  "iriFort",
  NULL,
  -1,
  f2py_module_methods,
  NULL,
  NULL,
  NULL,
  NULL
};
#endif

#if PY_VERSION_HEX >= 0x03000000
#define RETVAL m
PyObject *PyInit_iriFort(void) {
#else
#define RETVAL
PyMODINIT_FUNC initiriFort(void) {
#endif
  int i;
  PyObject *m,*d, *s;
#if PY_VERSION_HEX >= 0x03000000
  m = iriFort_module = PyModule_Create(&moduledef);
#else
  m = iriFort_module = Py_InitModule("iriFort", f2py_module_methods);
#endif
  Py_TYPE(&PyFortran_Type) = &PyType_Type;
  import_array();
  if (PyErr_Occurred())
    {PyErr_SetString(PyExc_ImportError, "can't initialize module iriFort (failed to import numpy)"); return RETVAL;}
  d = PyModule_GetDict(m);
  s = PyString_FromString("$Revision: $");
  PyDict_SetItemString(d, "__version__", s);
#if PY_VERSION_HEX >= 0x03000000
  s = PyUnicode_FromString(
#else
  s = PyString_FromString(
#endif
    "This module 'iriFort' is auto-generated with f2py (version:2).\nFunctions:\n"
"  outf,oarr = iri_sub(jf,jmag,alati,along,iyyyy,mmdd,dhour,heibeg,heiend,heistp,oarr)\n"
"COMMON blocks:\n""  /block7/ d1,xkk,fp30,fp3u,fp1,fp2\n""  /block6/ hmd,nmd,hdx\n""  /block5/ enight,e(4)\n""  /block4/ hme,nme,hef\n""  /const/ umr\n""  /block2/ b0,b1,c1\n""  /block1/ hmf2,nmf2,hmf1,f1reg\n""  /block8/ hs,tnhs,xsm(4),mm(5),dti(4),mxsm\n""  /argexp/ argmax\n""  /iounit/ konsol\n""  /blo11/ b2top,tc3,itopn,alg10,hcor1\n""  /blo10/ beta,eta,delta,zeta\n""  /const1/ humr,dumr\n""  /blote/ ahh(7),ate1,stte(6),dte(5)\n""  /const2/ icalls,nmono,iyearo,idaynro,rzino,igino,ut0\n""  /block3/ hz,t,hst\n""  /qtop/ y05,h05top,qf,xnetop,xm3000,hhalf,tau\n""  /findrlat/ flon,ryear\n"".");
  PyDict_SetItemString(d, "__doc__", s);
  iriFort_error = PyErr_NewException ("iriFort.error", NULL, NULL);
  Py_DECREF(s);
  for(i=0;f2py_routine_defs[i].name!=NULL;i++)
    PyDict_SetItemString(d, f2py_routine_defs[i].name,PyFortranObject_NewAsAttr(&f2py_routine_defs[i]));

/*eof initf2pywraphooks*/
/*eof initf90modhooks*/

  F2PyDict_SetItemString(d, "block7", PyFortranObject_New(f2py_block7_def,f2py_init_block7));
  F2PyDict_SetItemString(d, "block6", PyFortranObject_New(f2py_block6_def,f2py_init_block6));
  F2PyDict_SetItemString(d, "block5", PyFortranObject_New(f2py_block5_def,f2py_init_block5));
  F2PyDict_SetItemString(d, "block4", PyFortranObject_New(f2py_block4_def,f2py_init_block4));
  F2PyDict_SetItemString(d, "const", PyFortranObject_New(f2py_const_def,f2py_init_const));
  F2PyDict_SetItemString(d, "block2", PyFortranObject_New(f2py_block2_def,f2py_init_block2));
  F2PyDict_SetItemString(d, "block1", PyFortranObject_New(f2py_block1_def,f2py_init_block1));
  F2PyDict_SetItemString(d, "block8", PyFortranObject_New(f2py_block8_def,f2py_init_block8));
  F2PyDict_SetItemString(d, "argexp", PyFortranObject_New(f2py_argexp_def,f2py_init_argexp));
  F2PyDict_SetItemString(d, "iounit", PyFortranObject_New(f2py_iounit_def,f2py_init_iounit));
  F2PyDict_SetItemString(d, "blo11", PyFortranObject_New(f2py_blo11_def,f2py_init_blo11));
  F2PyDict_SetItemString(d, "blo10", PyFortranObject_New(f2py_blo10_def,f2py_init_blo10));
  F2PyDict_SetItemString(d, "const1", PyFortranObject_New(f2py_const1_def,f2py_init_const1));
  F2PyDict_SetItemString(d, "blote", PyFortranObject_New(f2py_blote_def,f2py_init_blote));
  F2PyDict_SetItemString(d, "const2", PyFortranObject_New(f2py_const2_def,f2py_init_const2));
  F2PyDict_SetItemString(d, "block3", PyFortranObject_New(f2py_block3_def,f2py_init_block3));
  F2PyDict_SetItemString(d, "qtop", PyFortranObject_New(f2py_qtop_def,f2py_init_qtop));
  F2PyDict_SetItemString(d, "findrlat", PyFortranObject_New(f2py_findrlat_def,f2py_init_findrlat));
/*eof initcommonhooks*/


#ifdef F2PY_REPORT_ATEXIT
  if (! PyErr_Occurred())
    on_exit(f2py_report_on_exit,(void*)"iriFort");
#endif

  return RETVAL;
}
#ifdef __cplusplus
}
#endif
