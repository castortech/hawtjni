/*******************************************************************************
 * Copyright (C) 2009-2011 FuseSource Corp.
 * 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include "foo.h"
#include <stdio.h>

void print_foo(struct foo *arg) {
   printf("foo@%p: { a: %d, b: %d, c: \"%s\", prev: @%p}\n", arg, arg->a, (int)arg->b, arg->c, arg->prev);
}

size_t foowork(struct foo **arg, int count) {
    size_t rc=0;
	int i=0;
	for( i=0; i < count; i++ ) {
	   rc = rc + (*arg)->a;
	   rc = rc + (*arg)->b;
	   arg++;
	}
	return rc;
}

void callmeback(void (*thecallback)(int number)) {
	thecallback(69);
}

int product(int u, int v) {
	return u * v;
}

int callproduct(t_somefunc prod) {
	return prod(2, 3);
}

struct foo * foo_add(struct foo *arg, int count) {
  return arg+count;
}

char * char_add(char *arg, int count) {
  return arg+count;
}

void passingtheenv (const char *who, JNIEnv *env) {
   printf("%s, the JNIEnv is at: %x\n", who, env);
}
