import cv2
import shutil

def draw(img , color:bool, stop_col:int):
    terminal_size = shutil.get_terminal_size()

    terminal_col = terminal_size[1]
    terminal_row = terminal_size[0]
    image_col = img.shape[1]
    image_row = img.shape[0]

    if (image_col/image_row < 1.77):
        resized_col = int(image_col/image_row*terminal_col)*2-1
        resized_row = terminal_col
    else:
        resized_col = int(image_col/image_row*terminal_row)
        resized_row = terminal_row//2
    img = cv2.resize(img, (resized_col, resized_row))

    for i in (range(resized_row)):
        for j in range(resized_col-1):
            if color:
                color_sw = 38
            else:
                color_sw = 48
            bgr = img[i,j]
            print("\033[%d;2;%d;%d;%dm%1s"%(color_sw ,int(bgr[2]/8) << 3,int(bgr[1]/8) << 3,int(bgr[0]/8) << 3,' '),end='')
        
        print("")

if __name__ == '__main__':
    import sys
    if len(sys.argv) == 1:
        print("Usage: python keyinput.py image_file")
        sys.exit(0)
    img = cv2.imread(sys.argv[1])
    draw(img, False, 1)
