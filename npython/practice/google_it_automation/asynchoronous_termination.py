#!/usr/bin/env python3

# Method asyncio.create_subprocess_exec() works much the same way as Popen()
# but calling wait() and communicate() on the returned objects does not block
# the processor, so the Python interpreter can be used in other things while
# the external subprocess doesn't return.

import asyncio


def first_example():
    proc = await asyncio.create_subprocess_exec(
        'ls', '-lha',
        stdout=asyncio.subprocess.PIPE,
        stderr=asyncio.subprocess.PIPE
    )

    stdout, stderr = await proc.communicate()

    print('Return code: ', proc.returncode)

    print('Stdout:\n ', stdout.decode())
    print('Stderr:\n ', stderr.decode())


async def second_example():
    print("Hello...")
    await asyncio.sleep(5)
    print("... World!")


asyncio.run(second_example())
