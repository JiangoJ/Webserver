import socket
import time
import random

HOST = "127.0.0.1"
PORT = 80
timeout = 100
clientCount = 20
msgsSent = 0

clients = []
msgCount = []

for i in range(clientCount):
    clientSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    clientSocket.connect((HOST, PORT))
    clients.append(clientSocket)
    msgCount.append(0)


timeout_start = time.time()
# while (time.time() < timeout_start + timeout):
    #time.sleep(float(random.randint(0,50))/1000)

while(msgsSent <= 10000):

    clientNumber = random.randint(0, clientCount-1)
    client = clients[clientNumber]
    msg = msgCount[clientNumber]

    data = "Hello Server"
    data += " This is Client " + str(clientNumber) + " Msg: " + str(msg)
    msgCount[clientNumber] = msg + 1

    client.send(data.encode())
    dataFromServer = client.recv(10000)

    print(dataFromServer.decode())

    msgsSent += 1

for i in range(clientCount):
    clients[i].close()


print("Total Time Taken: ", str(time.time() - timeout_start))

