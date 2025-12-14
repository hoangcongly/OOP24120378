import socket
import threading
import time

from common import TYPE_TEXT, TYPE_FRAME, send_packet, recv_packet
from video_stream import VideoStream

HOST = "0.0.0.0"
PORT = 5000

class ServerState:
    def __init__(self):
        self.playing = False
        self.stopped = False
        self.lock = threading.Lock()

    def set_playing(self, value: bool):
        with self.lock:
            self.playing = value

    def set_stopped(self):
        with self.lock:
            self.stopped = True

    def is_playing(self) -> bool:
        with self.lock:
            return self.playing

    def is_stopped(self) -> bool:
        with self.lock:
            return self.stopped

def handle_control(sock: socket.socket, state: ServerState):
    while not state.is_stopped():
        type_, payload = recv_packet(sock)
        if type_ is None:
            state.set_stopped()
            break

        if type_ == TYPE_TEXT:
            msg = payload.decode("utf-8").strip().lower()
            print(f"[Client] {msg}")

            if msg == "play":
                state.set_playing(True)
                send_packet(sock, TYPE_TEXT, b"SERVER: PLAY")

            elif msg == "pause":
                state.set_playing(False)
                send_packet(sock, TYPE_TEXT, b"SERVER: PAUSE")

            elif msg == "quit":
                state.set_playing(False)
                state.set_stopped()
                send_packet(sock, TYPE_TEXT, b"SERVER: BYE")
                break

            else:
                send_packet(sock, TYPE_TEXT, b"SERVER: UNKNOWN COMMAND")

def stream_video(sock: socket.socket, state: ServerState, video_path=None):
    vs = VideoStream(video_path=video_path)
    try:
        while not state.is_stopped():
            if state.is_playing():
                frame_bytes = vs.get_next_jpeg()
                if frame_bytes is None:
                    state.set_playing(False)
                    send_packet(sock, TYPE_TEXT, b"SERVER: END OF VIDEO")
                    break

                send_packet(sock, TYPE_FRAME, frame_bytes)
                time.sleep(1 / 25)
            else:
                time.sleep(0.05)
    finally:
        vs.release()
        sock.close()
        print("[Server] Stream thread ended.")

def main():
    srv = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    srv.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    srv.bind((HOST, PORT))
    srv.listen(1)
    print(f"[Server] Listening on {HOST}:{PORT}")

    client_sock, addr = srv.accept()
    print("[Server] Client connected from", addr)
    srv.close()

    state = ServerState()
    threading.Thread(target=handle_control, args=(client_sock, state), daemon=True).start()
    stream_video(client_sock, state, video_path=None)

if __name__ == "__main__":
    main()
