# server.py
import socket

HOST = "127.0.0.1"  # Standard loopback interface address (localhost)
PORT = 8888  # Port to listen on (non-privileged ports are > 1023)

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT))
    s.listen()
    while True:
        conn, addr = s.accept()
        with conn:
            print(f"Connected by {addr}")
            while True:
                data = conn.recv(1024)
                if data.decode() == "exit":
                    print("Client: exit")
                    exit()
                if not data:
                    break
                conn.sendall("Server: ".encode() + data)
                print("Server: " + data.decode())