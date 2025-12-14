import struct
import socket
from typing import Tuple, Optional

TYPE_TEXT = 1
TYPE_FRAME = 2

HEADER_FMT = "!BI"
HEADER_SIZE = struct.calcsize(HEADER_FMT)

def send_packet(sock: socket.socket, type_: int, payload: bytes) -> None:
    header = struct.pack(HEADER_FMT, type_, len(payload))
    sock.sendall(header + payload)

def _recv_exact(sock: socket.socket, n: int) -> Optional[bytes]:
    data = b""
    while len(data) < n:
        chunk = sock.recv(n - len(data))
        if not chunk:
            return None
        data += chunk
    return data

def recv_packet(sock: socket.socket) -> Tuple[Optional[int], Optional[bytes]]:
    header = _recv_exact(sock, HEADER_SIZE)
    if header is None:
        return None, None
    type_, length = struct.unpack(HEADER_FMT, header)
    payload = _recv_exact(sock, length)
    if payload is None:
        return None, None
    return type_, payload
