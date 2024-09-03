import subprocess

def set_vlc_wallpaper(video_path):
    # Path to VLC executable
    vlc_path = r"C:\Program Files\VideoLAN\VLC\vlc.exe"
    
    # Command to launch VLC in wallpaper mode
    command = [
        vlc_path,
        "--video-wallpaper",
        "--no-video-title-show",
        "--loop",
        video_path
    ]
    
    # Run the command
    subprocess.Popen(command)

if __name__ == "__main__":
    # Path to your video file
    video_path = r"C:\Users\user\Pictures\goku-ultra-instinct_2.3840x2160.mp4"
    
    set_vlc_wallpaper(video_path)
