# client.py
import socket
import threading
import cv2

from common import TYPE_TEXT, TYPE_FRAME, send_packet, recv_packet
from video_stream import jpeg_to_frame

HOST = "127.0.0.1"   # đổi sang IP máy server nếu chạy 2 máy
PORT = 5000


def recv_thread(sock: socket.socket):
    """Nhận video + text từ server."""
    while True:
        type_, payload = recv_packet(sock)
        if type_ is None:
            print("[Client] Disconnected from server.")
            break

        if type_ == TYPE_FRAME:
            frame = jpeg_to_frame(payload)
            if frame is None:
                continue
            cv2.imshow("Video Stream", frame)
            # không dùng waitKey lớn, chỉ 1ms để loop
            if cv2.waitKey(1) == 27:  # ESC: thoát
                print("[Client] ESC pressed, sending quit.")
                send_packet(sock, TYPE_TEXT, b"quit")
                break
        elif type_ == TYPE_TEXT:
            msg = payload.decode("utf-8", errors="ignore")
            print(msg)

    cv2.destroyAllWindows()
    sock.close()


def main():
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.connect((HOST, PORT))
    print(f"[Client] Connected to {HOST}:{PORT}")

    t = threading.Thread(target=recv_thread, args=(sock,), daemon=True)
    t.start()

    try:
        while True:
            cmd = input("Command (play/pause/quit): ").strip()
            if not cmd:
                continue
            send_packet(sock, TYPE_TEXT, cmd.encode("utf-8"))
            if cmd.lower() == "quit":
                break
    except KeyboardInterrupt:
        send_packet(sock, TYPE_TEXT, b"quit")
    finally:
        sock.close()
        print("[Client] Bye.")


if __name__ == "__main__":
    main()
