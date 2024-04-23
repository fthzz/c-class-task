from ultralytics import YOLO
import cv2
import rospy
from std_msgs.msg import String

class LR_detect:
    def __init__(self):
        self.dirpath="/home/fthzzz/Desktop/robocup_LR_yolov8/runs/detect/train/weights/best.pt"

    def YOLO(self):
        model=YOLO(self.dirpath)

        #接收图片代码

        results = model.predict(frame)
        for output in results:
            cls=output.boxes.cls
        list=[]
        list=cls.cpu().numpy().tolist()
        if list[0]==1.0:
            val='R'
        else:
            val='L'
        return val

    def ros(self,val):
        rospy.init_node("LR_node")
        pub = rospy.Publisher("LR_detect", String, queue_size=100)

        rate = rospy.Rate(10)

        while not rospy.is_shutdown():
            msg = String()
            msg.data =val
            pub.publish(msg)
            rate.sleep()


if __name__ == '__main__':
    lr=LR_detect()
    val=lr.YOLO()
    lr.ros(val)