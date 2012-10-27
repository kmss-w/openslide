/*
 *  OpenSlide, a library for reading whole slide image files
 *
 *  Copyright (c) 2007-2008 Carnegie Mellon University
 *  All rights reserved.
 *
 *  OpenSlide is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as
 *  published by the Free Software Foundation, version 2.1.
 *
 *  OpenSlide is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with OpenSlide. If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#ifndef OPENSLIDE_OPENSLIDE_CACHE_H_
#define OPENSLIDE_OPENSLIDE_CACHE_H_

#include <config.h>

#include "openslide-private.h"

#define _OPENSLIDE_USEFUL_CACHE_SIZE 1024*1024*32

struct _openslide_cache;
struct _openslide_cache_entry;

// constructor/destructor
struct _openslide_cache *_openslide_cache_create(int capacity_in_bytes);

void _openslide_cache_destroy(struct _openslide_cache *cache);


// cache size
int _openslide_cache_get_capacity(struct _openslide_cache *cache);

void _openslide_cache_set_capacity(struct _openslide_cache *cache,
				   int capacity_in_bytes);

// put and get
void _openslide_cache_put(struct _openslide_cache *cache,
			  int64_t x,
			  int64_t y,
			  struct _openslide_level *level,
			  void *data,
			  int size_in_bytes,
			  struct _openslide_cache_entry **entry);

void *_openslide_cache_get(struct _openslide_cache *cache,
			   int64_t x,
			   int64_t y,
			   struct _openslide_level *level,
			   struct _openslide_cache_entry **entry);

// value unref
void _openslide_cache_entry_unref(struct _openslide_cache_entry *entry);

#endif
