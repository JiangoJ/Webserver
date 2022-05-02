from pydoc import cli
import socket
import time
import random
import argparse
import asyncio
import sys
import aioconsole


HOST = "127.0.0.1"
PORT = 80
timeout = 100
msgsSent = 0

clientSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
clientSocket.connect((HOST, PORT))

parser = argparse.ArgumentParser()
parser.add_argument('name', type=str)

args = parser.parse_args()

name = args.name
inputStr = ''

async def monitor_server():
    reader, writer = await asyncio.open_connection(
        HOST, port=PORT
    )
    while(1):
        data = await reader.read(1000)
        print(data.decode(),'\n')

async def ainput(string: str) -> str:
    await asyncio.get_event_loop().run_in_executor(
            None, lambda s=string: sys.stdout.write(s+' '))
    return await asyncio.get_event_loop().run_in_executor(
            None, sys.stdin.readline)

async def read_cmd():
    while(1):
        input = await aioconsole.ainput('Message: ')
        input = name + " says: " + input
        clientSocket.send(input.encode())


try:
    asyncio.get_event_loop().run_until_complete(asyncio.wait([monitor_server(),read_cmd()]))
except KeyboardInterrupt:
    quit()