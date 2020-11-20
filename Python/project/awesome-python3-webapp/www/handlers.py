#!/usr/bin/env python3
# -*- coding: utf-8 -*-

' url handlers '

import re, time, json, logging, hashlib, base64, asyncio
logging.basicConfig(level=logging.INFO, format='%(asctime)s %(process)d %(thread)d %(levelname)s [%(funcName)s]: %(message)s')

from coroweb import get, post

from models import User, Comment, Blog, next_id

@get('/test')
async def test(request):
    users = await User.findAll()
    return {
        '__template__': 'test.html',
        'users':users
    }

@get('/')
async def index(request):
    summary = 'summary 1, summary 2, summary 3'
    blogs = [
        Blog(id='1', name='Test1 Blog', summary=summary, created_at=time.time() - 120),
        Blog(id='2', name='Test2 Blog', summary=summary, created_at=time.time() - 3600),
        Blog(id='3', name='Test3 Blog', summary=summary, created_at=time.time() - 7200),
    ]
    return {
        '__template__': 'blogs.html',
        'blogs': blogs
    }