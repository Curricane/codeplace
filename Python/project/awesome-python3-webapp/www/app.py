#!/usr/bin/env python3
# -*- coding: utf-8 -*-


__author__ = 'chenmc'

'''
async web application.
'''

import logging; logging.basicConfig(level=logging.INFO)

import asyncio, os, json, time
from datetime import datetime

from aiohttp import web

logging.basicConfig(level=logging.INFO, format='%(asctime)s %(process)d %(thread)d %(levelname)s [%(funcName)s]: %(message)s')

def index(request):
    # 需要加headers不然不会正常显示
    return web.Response(body='<h1>Awesome</h1>', headers={'content-type': 'text/html'}) 

@asyncio.coroutine
def init(loop):
    app = web.Application(loop=loop)
    app.router.add_route('GET', '/', index)
    srv = yield from loop.create_server(app.make_handler(), '127.0.0.1', 9000)
    logging.info('server started at http://127.0.0.1:9000...')
    return srv

loop = asyncio.get_event_loop()
loop.run_until_complete(init(loop))
loop.run_forever()