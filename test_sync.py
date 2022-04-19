import socket
import time
import random

HOST = "127.0.0.1"
PORT = 80
msgsSent = 0

timeout_start = time.time()

while(msgsSent <= 10000):

    clientSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    clientSocket.connect((HOST, PORT))

    data = "Hello Server"
    data += " This is Client 1" 

    clientSocket.send(data.encode())
    dataFromServer = clientSocket.recv(10000)

    print(dataFromServer.decode())

    msgsSent += 1

    clientSocket.close()

print("Total Time Taken: ", str(time.time() - timeout_start))

