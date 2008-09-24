/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2008 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: Akshat Gupta <g.akshat@gmail.com>                            |
  |         Elizabeth Smith <auroraeosrose@php.net>                      |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#include "php_cairo_api.h"
#include "php_cairo_internal.h"
#include <zend_exceptions.h>

/* {{{ arginfo */
ZEND_BEGIN_ARG_INFO_EX(CairoPattern__set_matrix_args, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
  ZEND_ARG_OBJ_INFO(0, m, CairoMatrix, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(CairoGradient__add_color_stop_rgb_args, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 4)
  ZEND_ARG_INFO(0, offset)
  ZEND_ARG_INFO(0, red)
  ZEND_ARG_INFO(0, green)
  ZEND_ARG_INFO(0, blue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(CairoGradient__add_color_stop_rgba_args, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 5)
  ZEND_ARG_INFO(0, offset)
  ZEND_ARG_INFO(0, red)
  ZEND_ARG_INFO(0, green)
  ZEND_ARG_INFO(0, blue)
  ZEND_ARG_INFO(0, alpha)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(CairoLinearGradient____construct_args, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 3)
  ZEND_ARG_INFO(0, y0)
  ZEND_ARG_INFO(0, x1)
  ZEND_ARG_INFO(0, y1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(CairoRadialGradient____constuct_args, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 6)
  ZEND_ARG_INFO(0, cx0)
  ZEND_ARG_INFO(0, cy0)
  ZEND_ARG_INFO(0, radius0)
  ZEND_ARG_INFO(0, cx1)
  ZEND_ARG_INFO(0, cy1)
  ZEND_ARG_INFO(0, radius1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(CairoSolidPattern____construct_args, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 2)
  ZEND_ARG_INFO(0, g)
  ZEND_ARG_INFO(0, b)
  ZEND_ARG_INFO(0, a)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(CairoPattern__set_extend_args, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
  ZEND_ARG_INFO(0, extend)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(CairoSurfacePattern__set_filter_args, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
  ZEND_ARG_INFO(0, filter)
ZEND_END_ARG_INFO()
/* }}} */

/* {{{ Class CairoPattern */


/* {{{ Methods */


/* {{{ proto void contruct()
   */
PHP_METHOD(CairoPattern, __construct)
{
	zend_throw_exception(CairoException_ce_ptr, "CairoPattern cannot be constructed", 0 TSRMLS_CC);
}
/* }}} __construct */

/* {{{ proto object getMatrix()
   */
PHP_METHOD(CairoPattern, getMatrix)
{

	zval * _this_zval = NULL;
	cairo_matrix_t matrix;
	cairo_pattern_object *curr;
	cairo_matrix_object *mobj;
	zend_class_entry *ce;
	if (zend_parse_method_parameters(ZEND_NUM_ARGS() TSRMLS_CC, getThis(), "O", &_this_zval, CairoPattern_ce_ptr) == FAILURE) {
		return;
	}

	curr = (cairo_pattern_object *)zend_objects_get_address(_this_zval TSRMLS_CC);

	cairo_pattern_get_matrix(curr->pattern, &matrix);
	ce = get_CairoMatrix_ce_ptr();
	object_init_ex(return_value, ce);
	mobj = (cairo_matrix_object *)zend_objects_get_address(return_value TSRMLS_CC);
	mobj->matrix = matrix;
}
/* }}} getMatrix */



/* {{{ proto void setMatrix(object m)
   */
PHP_METHOD(CairoPattern, setMatrix)
{

	zval * _this_zval = NULL;
	zval * m = NULL;
	cairo_pattern_object *curr;
	cairo_matrix_object *mobj;

	if (zend_parse_method_parameters(ZEND_NUM_ARGS() TSRMLS_CC, getThis(), "Oo", &_this_zval, CairoPattern_ce_ptr, &m) == FAILURE) {
		return;
	}

	curr = (cairo_pattern_object *)zend_objects_get_address(_this_zval TSRMLS_CC);
	mobj = (cairo_matrix_object *)zend_objects_get_address(m TSRMLS_CC);
	cairo_pattern_set_matrix(curr->pattern, &mobj->matrix);
}
/* }}} setMatrix */


/* {{{ proto void setExtend(int extend)
	*/
PHP_METHOD(CairoPattern, setExtend)
{
	long extend;
	cairo_pattern_object *curr;
	zval * _this_zval = NULL;
	if (zend_parse_method_parameters(ZEND_NUM_ARGS() TSRMLS_CC, getThis(), "Ol", &_this_zval, CairoPattern_ce_ptr, &extend) == FAILURE) {
			return;
	}
	curr = (cairo_pattern_object *)zend_objects_get_address(_this_zval TSRMLS_CC);
	cairo_pattern_set_extend(curr->pattern, extend);
	PHP_CAIRO_PATTERN_ERROR(curr->pattern);
	
}

/* }}} setExtend */


/* {{{ proto void getExtend()
	*/
PHP_METHOD(CairoPattern, getExtend)
{
	long extend;
	cairo_pattern_object *curr;
	zval * _this_zval = NULL;
	if (zend_parse_method_parameters(ZEND_NUM_ARGS() TSRMLS_CC, getThis(), "O", &_this_zval, CairoPattern_ce_ptr) == FAILURE) {
		return;
	}
	curr = (cairo_pattern_object *)zend_objects_get_address(_this_zval TSRMLS_CC);
	extend = cairo_pattern_get_extend(curr->pattern);
	RETURN_LONG(extend);
}
/* }}} setExtend */


static zend_function_entry CairoPattern_methods[] = {
	PHP_ME(CairoPattern, __construct, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
	PHP_ME(CairoPattern, getMatrix, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(CairoPattern, setMatrix, CairoPattern__set_matrix_args, ZEND_ACC_PUBLIC)
	PHP_ME(CairoPattern, getExtend, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(CairoPattern, setExtend, CairoPattern__set_extend_args, ZEND_ACC_PUBLIC)
	{ NULL, NULL, NULL }
};

/* }}} Methods */

static zend_object_handlers CairoPattern_handlers;

static void CairoPattern_object_dtor(void *object TSRMLS_DC)
{
	cairo_pattern_object *pattern = (cairo_pattern_object *)object;
	zend_hash_destroy(pattern->std.properties);
	FREE_HASHTABLE(pattern->std.properties);
	if(pattern->pattern){
		cairo_pattern_destroy(pattern->pattern);
	}
	efree(object);
}

static zend_object_value CairoPattern_object_new(zend_class_entry *ce TSRMLS_DC)
{
	zend_object_value retval;
	cairo_pattern_object *pattern;
	zval *temp;
	pattern = emalloc(sizeof(cairo_pattern_object));
	memset(pattern,0,sizeof(cairo_pattern_object));
	pattern->std.ce = ce;
	ALLOC_HASHTABLE(pattern->std.properties);
	zend_hash_init(pattern->std.properties, 0, NULL, ZVAL_PTR_DTOR,0);
	zend_hash_copy(pattern->std.properties, &ce->default_properties, (copy_ctor_func_t) zval_add_ref, (void *) &temp, sizeof(zval *));
	retval.handle = zend_objects_store_put(pattern, NULL, (zend_objects_free_object_storage_t)CairoPattern_object_dtor, NULL TSRMLS_CC);
	retval.handlers = &CairoPattern_handlers;
	return retval;
}


void class_init_CairoPattern(TSRMLS_D)
{
	zend_class_entry ce;

	INIT_CLASS_ENTRY(ce, "CairoPattern", CairoPattern_methods);
	CairoPattern_ce_ptr = zend_register_internal_class(&ce TSRMLS_CC);
	CairoPattern_ce_ptr->create_object = CairoPattern_object_new;
	memcpy(&CairoPattern_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
	CairoPattern_handlers.clone_obj = NULL;
}

/* }}} Class CairoPattern */

/* {{{ Class CairoGradient */


/* {{{ Methods */


/* {{{ proto void construct()
   */
PHP_METHOD(CairoGradient, __construct)
{
	zend_throw_exception(CairoException_ce_ptr, "CairoGradient cannot be constructed", 0 TSRMLS_CC);
}
/* }}} __construct */



/* {{{ proto void addColorStopRgb(float offset, float red, float green, float blue)
   */
PHP_METHOD(CairoGradient, addColorStopRgb)
{

	zval * _this_zval = NULL;
	double offset = 0.0;
	double red = 0.0;
	double green = 0.0;
	double blue = 0.0;
	cairo_pattern_object *curr;


	if (zend_parse_method_parameters(ZEND_NUM_ARGS() TSRMLS_CC, getThis(), "Odddd", &_this_zval, CairoGradient_ce_ptr, &offset, &red, &green, &blue) == FAILURE) {
		return;
	}

	curr = (cairo_pattern_object *)zend_objects_get_address(_this_zval TSRMLS_CC);
	cairo_pattern_add_color_stop_rgb(curr->pattern, offset, red, green, blue);
	PHP_CAIRO_PATTERN_ERROR(curr->pattern);
}
/* }}} addColorStopRgb */



/* {{{ proto void addColorStopRgba(float offset, float red, float green, float blue, float alpha)
   */
PHP_METHOD(CairoGradient, addColorStopRgba)
{

	zval * _this_zval = NULL;
	double offset = 0.0;
	double red = 0.0;
	double green = 0.0;
	double blue = 0.0;
	double alpha = 0.0;
	cairo_pattern_object *curr;


	if (zend_parse_method_parameters(ZEND_NUM_ARGS() TSRMLS_CC, getThis(), "Oddddd", &_this_zval, CairoGradient_ce_ptr, &offset, &red, &green, &blue, &alpha) == FAILURE) {
		return;
	}

	curr = (cairo_pattern_object *)zend_objects_get_address(_this_zval TSRMLS_CC);
	cairo_pattern_add_color_stop_rgba(curr->pattern, offset, red, green, blue, alpha);
	PHP_CAIRO_PATTERN_ERROR(curr->pattern);
}
/* }}} addColorStopRgba */



static zend_function_entry CairoGradient_methods[] = {
	PHP_ME(CairoGradient, __construct, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
	PHP_ME(CairoGradient, addColorStopRgb, CairoGradient__add_color_stop_rgb_args, ZEND_ACC_PUBLIC)
	PHP_ME(CairoGradient, addColorStopRgba, CairoGradient__add_color_stop_rgba_args, ZEND_ACC_PUBLIC)
	{ NULL, NULL, NULL }
};

/* }}} Methods */

static zend_object_handlers CairoGradient_handlers;

static zend_object_value CairoGradient_object_new(zend_class_entry *ce TSRMLS_DC)
{
	zend_object_value retval;
	retval = CairoPattern_object_new(ce TSRMLS_CC);
	retval.handlers = &CairoGradient_handlers;
	return retval;
}

void class_init_CairoGradient(TSRMLS_D)
{
	zend_class_entry ce;
	INIT_CLASS_ENTRY(ce, "CairoGradient", CairoGradient_methods);
	CairoGradient_ce_ptr = zend_register_internal_class_ex(&ce, CairoPattern_ce_ptr, "CairoPattern" TSRMLS_CC);
	CairoGradient_ce_ptr->create_object = CairoGradient_object_new;
	memcpy(&CairoGradient_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
}


/* }}} Class CairoGradient */

/* {{{ Class CairoLinearGradient */


/* {{{ Methods */


/* {{{ proto void construct(float x0, float y0, float x1, float y1)
   */
PHP_METHOD(CairoLinearGradient, __construct)
{
	zval * _this_zval;

	double x0 = 0.0;
	double y0 = 0.0;
	double x1 = 0.0;
	double y1 = 0.0;
	cairo_pattern_object *curr;


	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dddd", &x0, &y0, &x1, &y1) == FAILURE) {
		return;
	}

	_this_zval = getThis();
	curr = (cairo_pattern_object *)zend_objects_get_address(_this_zval TSRMLS_CC);
	curr->pattern = cairo_pattern_create_linear(x0, y0, x1, y1);

}
/* }}} __construct */



/* {{{ proto array getLinearPoints()
   */
PHP_METHOD(CairoLinearGradient, getLinearPoints)
{

	zval * _this_zval = NULL;
	double x0, y0, x1, y1;
	cairo_pattern_object *curr;

	if (zend_parse_method_parameters(ZEND_NUM_ARGS() TSRMLS_CC, getThis(), "O", &_this_zval, CairoLinearGradient_ce_ptr) == FAILURE) {
		return;
	}

	curr = (cairo_pattern_object *)zend_objects_get_address(_this_zval TSRMLS_CC);
	cairo_pattern_get_linear_points(curr->pattern, &x0, &y0, &x1, &y1);

	array_init(return_value);
	add_assoc_double(return_value, "x0", x0);
	add_assoc_double(return_value, "y0", y0);
	add_assoc_double(return_value, "x1", x1);
	add_assoc_double(return_value, "y1", y1);

}
/* }}} getLinearPoints */


static zend_function_entry CairoLinearGradient_methods[] = {
	PHP_ME(CairoLinearGradient, __construct, CairoLinearGradient____construct_args, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
	PHP_ME(CairoLinearGradient, getLinearPoints, NULL, ZEND_ACC_PUBLIC)
	{ NULL, NULL, NULL }
};

/* }}} Methods */

static zend_object_handlers CairoLinearGradient_handlers;

static zend_object_value CairoLinearGradient_object_new(zend_class_entry *ce TSRMLS_DC)
{
	zend_object_value retval;
	retval = CairoGradient_object_new(ce TSRMLS_CC);
	retval.handlers = &CairoLinearGradient_handlers;
	return retval;
}

void class_init_CairoLinearGradient(TSRMLS_D)
{
	zend_class_entry ce;
	INIT_CLASS_ENTRY(ce, "CairoLinearGradient", CairoLinearGradient_methods);
	CairoLinearGradient_ce_ptr = zend_register_internal_class_ex(&ce, CairoGradient_ce_ptr, "CairoGradient" TSRMLS_CC);
	CairoLinearGradient_ce_ptr->create_object = CairoLinearGradient_object_new;
	memcpy(&CairoLinearGradient_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
}


/* }}} Class CairoLinearGradient */

/* {{{ Class CairoRadialGradient */


/* {{{ Methods */


/* {{{ proto void construct(float cx0, float cy0, float radius0, float cx1, float cy1, float radius1)
   */
PHP_METHOD(CairoRadialGradient, __construct)
{

	zval * _this_zval = NULL;
	double cx0 = 0.0;
	double cy0 = 0.0;
	double radius0 = 0.0;
	double cx1 = 0.0;
	double cy1 = 0.0;
	double radius1 = 0.0;
	cairo_pattern_object *curr;


	if (zend_parse_method_parameters(ZEND_NUM_ARGS() TSRMLS_CC, getThis(), "Odddddd", &_this_zval, CairoRadialGradient_ce_ptr, &cx0, &cy0, &radius0, &cx1, &cy1, &radius1) == FAILURE) {
		return;
	}

	curr = (cairo_pattern_object *)zend_objects_get_address(_this_zval TSRMLS_CC);
	curr->pattern = cairo_pattern_create_radial(cx0, cy0, radius0, cx1, cy1, radius1);

}
/* }}} __construct */



/* {{{ proto array getRadialCircles()
   */
PHP_METHOD(CairoRadialGradient, getRadialCircles)
{

	zval * _this_zval = NULL;
	double x0, y0, r0, x1, y1, r1;
	cairo_pattern_object *curr;

	if (zend_parse_method_parameters(ZEND_NUM_ARGS() TSRMLS_CC, getThis(), "O", &_this_zval, CairoRadialGradient_ce_ptr) == FAILURE) {
		return;
	}

	curr = (cairo_pattern_object *)zend_objects_get_address(_this_zval TSRMLS_CC);
	cairo_pattern_get_radial_circles(curr->pattern, &x0, &y0, &r0, &x1, &y1, &r1);

	array_init(return_value);
	add_assoc_double(return_value, "x0", x0);
	add_assoc_double(return_value, "y0", y0);
	add_assoc_double(return_value, "r0", r0);
	add_assoc_double(return_value, "x1", x1);
	add_assoc_double(return_value, "y1", y1);
	add_assoc_double(return_value, "r1", r1);

}
/* }}} getRadialCircles */


static zend_function_entry CairoRadialGradient_methods[] = {
	PHP_ME(CairoRadialGradient, __construct, CairoRadialGradient____constuct_args, ZEND_ACC_PUBLIC| ZEND_ACC_CTOR)
	PHP_ME(CairoRadialGradient, getRadialCircles, NULL, ZEND_ACC_PUBLIC)
	{ NULL, NULL, NULL }
};

/* }}} Methods */

static zend_object_handlers CairoRadialGradient_handlers;

static zend_object_value CairoRadialGradient_object_new(zend_class_entry *ce TSRMLS_DC)
{
	zend_object_value retval;
	retval = CairoGradient_object_new(ce TSRMLS_CC);
	retval.handlers = &CairoRadialGradient_handlers;
	return retval;
}

void class_init_CairoRadialGradient(TSRMLS_D)
{
	zend_class_entry ce;
	INIT_CLASS_ENTRY(ce, "CairoRadialGradient", CairoRadialGradient_methods);
	CairoRadialGradient_ce_ptr = zend_register_internal_class_ex(&ce, CairoGradient_ce_ptr, "CairoGradient" TSRMLS_CC);
	CairoRadialGradient_ce_ptr->create_object = CairoRadialGradient_object_new;
	memcpy(&CairoRadialGradient_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
}

/* }}} Class CairoRadialGradient */

/* {{{ Class CairoSolidPattern */


/* {{{ Methods */


/* {{{ proto void construct(float r, float g, float b [, float a])
   */
PHP_METHOD(CairoSolidPattern, __construct)
{
	zval * _this_zval;

	double r = 0.0;
	double g = 0.0;
	double b = 0.0;
	double a = 1.0;
	cairo_pattern_object *curr;


	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ddd|d", &r, &g, &b, &a) == FAILURE) {
		return;
	}

	_this_zval = getThis();
	curr = (cairo_pattern_object *)zend_objects_get_address(_this_zval TSRMLS_CC);
	curr->pattern = cairo_pattern_create_rgba(r, g, b, a);

}
/* }}} __construct */



/* {{{ proto array getRgba()
   */
PHP_METHOD(CairoSolidPattern, getRgba)
{

	zval * _this_zval = NULL;
	double r,g,b,a;
	cairo_pattern_object *curr;

	if (zend_parse_method_parameters(ZEND_NUM_ARGS() TSRMLS_CC, getThis(), "O", &_this_zval, CairoSolidPattern_ce_ptr) == FAILURE) {
		return;
	}

	curr = (cairo_pattern_object *)zend_objects_get_address(_this_zval TSRMLS_CC);
	cairo_pattern_get_rgba(curr->pattern, &r, &g, &b, &a);

	array_init(return_value);
	add_assoc_double(return_value, "red", r);
	add_assoc_double(return_value, "green", g);
	add_assoc_double(return_value, "blue", b);
	add_assoc_double(return_value, "alpha", a);

}
/* }}} getRgba */


static zend_function_entry CairoSolidPattern_methods[] = {
	PHP_ME(CairoSolidPattern, __construct, CairoSolidPattern____construct_args, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
	PHP_ME(CairoSolidPattern, getRgba, NULL, ZEND_ACC_PUBLIC)
	{ NULL, NULL, NULL }
};

/* }}} Methods */

static zend_object_handlers CairoSolidPattern_handlers;

static zend_object_value CairoSolidPattern_object_new(zend_class_entry *ce TSRMLS_DC)
{
	zend_object_value retval;
	retval = CairoPattern_object_new(ce TSRMLS_CC);
	retval.handlers = &CairoSolidPattern_handlers;
	return retval;

}

void class_init_CairoSolidPattern(TSRMLS_D)
{
	zend_class_entry ce;

	INIT_CLASS_ENTRY(ce, "CairoSolidPattern", CairoSolidPattern_methods);
	CairoSolidPattern_ce_ptr = zend_register_internal_class_ex(&ce, CairoPattern_ce_ptr, "CairoPattern" TSRMLS_CC);
	CairoSolidPattern_ce_ptr->create_object = CairoSolidPattern_object_new;
	memcpy(&CairoSolidPattern_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
}

/* }}} Class CairoSolidPattern */

/* {{{ Class CairoSurfacePattern */


/* {{{ Methods */


/* {{{ proto void construct(object s)
   */
PHP_METHOD(CairoSurfacePattern, __construct)
{
	zval * _this_zval;

	zval * s = NULL;
	cairo_pattern_object *curr;
	cairo_surface_object *sobj;


	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "o", &s) == FAILURE) {
		return;
	}

	_this_zval = getThis();
	curr = (cairo_pattern_object *)zend_objects_get_address(_this_zval TSRMLS_CC);
	sobj = (cairo_surface_object *)zend_objects_get_address(s TSRMLS_CC);
	curr->pattern = cairo_pattern_create_for_surface(sobj->surface);
	
}
/* }}} __construct */


/* {{{ proto int getFilter()
   */
PHP_METHOD(CairoSurfacePattern, getFilter)
{
	zval * _this_zval = NULL;
	cairo_pattern_object *curr;


	if (zend_parse_method_parameters(ZEND_NUM_ARGS() TSRMLS_CC, getThis(), "O", &_this_zval, CairoSurfacePattern_ce_ptr) == FAILURE) {
		return;
	}

	curr = (cairo_pattern_object *)zend_objects_get_address(_this_zval TSRMLS_CC);
	RETURN_LONG(cairo_pattern_get_filter(curr->pattern));
}
/* }}} getFilter */



/* {{{ proto object getSurface()
   */
PHP_METHOD(CairoSurfacePattern, getSurface)
{
	zend_class_entry *surface_ce;
	cairo_surface_t *surface;
	zval * _this_zval = NULL;
	cairo_pattern_object *curr;
	cairo_surface_object *sobj;


	if (zend_parse_method_parameters(ZEND_NUM_ARGS() TSRMLS_CC, getThis(), "O", &_this_zval, CairoSurfacePattern_ce_ptr) == FAILURE) {
		return;
	}

	curr = (cairo_pattern_object *)zend_objects_get_address(_this_zval TSRMLS_CC);	
	cairo_pattern_get_surface(curr->pattern, &surface);
	surface_ce = get_CairoSurface_ce_ptr(surface);

	object_init_ex(return_value,surface_ce);
	sobj = (cairo_surface_object *)zend_objects_get_address(return_value TSRMLS_CC);
	sobj->surface = cairo_surface_reference(surface);
}
/* }}} getSurface */

/* {{{ proto void setFilter(int filter)
   */
PHP_METHOD(CairoSurfacePattern, setFilter)
{

	zval * _this_zval = NULL;
	long filter = 0;
	cairo_pattern_object *curr;


	if (zend_parse_method_parameters(ZEND_NUM_ARGS() TSRMLS_CC, getThis(), "Ol", &_this_zval, CairoSurfacePattern_ce_ptr, &filter) == FAILURE) {
		return;
	}
	
	curr = (cairo_pattern_object *)zend_objects_get_address(_this_zval TSRMLS_CC);

	cairo_pattern_set_filter(curr->pattern, filter);
}
/* }}} setFilter */


static zend_function_entry CairoSurfacePattern_methods[] = {
	PHP_ME(CairoSurfacePattern, __construct, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
	PHP_ME(CairoSurfacePattern, getFilter, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(CairoSurfacePattern, getSurface, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(CairoSurfacePattern, setFilter, CairoSurfacePattern__set_filter_args, ZEND_ACC_PUBLIC)
	{ NULL, NULL, NULL }
};

/* }}} Methods */

static zend_object_handlers CairoSurfacePattern_handlers;

static zend_object_value CairoSurfacePattern_object_new(zend_class_entry *ce TSRMLS_DC)
{
	zend_object_value retval;
	retval = CairoPattern_object_new(ce TSRMLS_CC);
	retval.handlers = &CairoSurfacePattern_handlers;
	return retval;
}

void class_init_CairoSurfacePattern(TSRMLS_D)
{
	zend_class_entry ce;
	INIT_CLASS_ENTRY(ce, "CairoSurfacePattern", CairoSurfacePattern_methods);
	CairoSurfacePattern_ce_ptr = zend_register_internal_class_ex(&ce, CairoPattern_ce_ptr, "CairoPattern" TSRMLS_CC);
	CairoSurfacePattern_ce_ptr->create_object = CairoSurfacePattern_object_new;
	memcpy(&CairoSurfacePattern_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
}


/* }}} Class CairoSurfacePattern */ 

/* {{{ Helper functions */

PHP_CAIRO_API zend_class_entry * get_CairoPattern_ce_ptr(cairo_pattern_t *pattern)
{
	zend_class_entry *type;
	if(pattern == NULL)
		return NULL;
	switch(cairo_pattern_get_type(pattern)) {
		case CAIRO_PATTERN_TYPE_SOLID:
			type = CairoSolidPattern_ce_ptr;
			break;
		case CAIRO_PATTERN_TYPE_SURFACE:
			type = CairoSurfacePattern_ce_ptr;
			break;
		case CAIRO_PATTERN_TYPE_LINEAR:
			type = CairoLinearGradient_ce_ptr;
			break;
		case CAIRO_PATTERN_TYPE_RADIAL:
			type = CairoRadialGradient_ce_ptr;
			break;
		default:
			php_error(E_WARNING,"Unsupported Pattern");
			return NULL;
	}
	return type;
}
/* }}} Helper functions */	

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw = 4 ts = 4 fdm = marker
 * vim<600: noet sw = 4 ts = 4
 */