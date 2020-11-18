#!/usr/bin/env python3

import orm
from models import User, Blog, Comment
import asyncio

g_loop = asyncio.get_event_loop()


async def test(loop):
    print('start create_pool...')
    await orm.create_pool(loop, user='www-data', password='www-data', db='awesome')
    print('after create_pool...')
    u = User(name='Test2', email='test2@example.com', passwd='1234567890', image='about:blank')
    await u.save()


if __name__ == '__main__':
    g_loop.run_until_complete(test(g_loop))
