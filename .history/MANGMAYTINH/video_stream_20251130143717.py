import cv2
import numpy as np
from typing import Optional

class VideoStream:
    def __init__(self, video_path: Optional[str] = None, cam_index: int = 0):
        if video_path is not None:
            self.cap = cv2.VideoCapture(video_path)
        else:
            self.cap = cv2.VideoCapture(cam_index)

        if not self.cap.isOpened():
            raise RuntimeError("Cannot open video source")

    def get_next_jpeg(self, quality: int = 80) -> Optional[bytes]:
        ret, frame = self.cap.read()
        if not ret:
            return None
        encode_param = [int(cv2.IMWRITE_JPEG_QUALITY), quality]
        ok, enc = cv2.imencode(".jpg", frame, encode_param)
        if not ok:
            return None
        return enc.tobytes()

    def release(self):
        self.cap.release()

def jpeg_to_frame(data: bytes):
    nparr = np.frombuffer(data, np.uint8)
    frame = cv2.imdecode(nparr, cv2.IMREAD_COLOR)
    return frame
