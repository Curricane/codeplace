#!/usr/bin/env python3
# -*- coding: utf-8 -*-

' url handlers '

import re, time, json, logging, hashlib, base64, asyncio
logging.basicConfig(level=logging.INFO, format='%(asctime)s %(process)d %(thread)d %(levelname)s [%(funcName)s]: %(message)s')

from coroweb import get, post

from models import User, Comment, Blog, next_id

@get('/')
async def index(request):
    users = await User.findAll()
    return {
        '__template__': 'test.html',
        'users':users
    }