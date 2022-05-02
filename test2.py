from pydoc import cli
import socket
import time
import random
import argparse

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

timeout_start = time.time()
# while (time.time() < timeout_start + timeout):
    #time.sleep(float(random.randint(0,50))/1000)

while(msgsSent <= 10):
    
    time.sleep(random.randint(1, 5))

    data = "Name: " + name + " Msg: " + str(msgsSent)

    clientSocket.send(data.encode())
    dataFromServer = clientSocket.recv(1000)

    print(dataFromServer.decode(), '\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n')

    msgsSent += 1

clientSocket.close()


print("Total Time Taken: ", str(time.time() - timeout_start))
