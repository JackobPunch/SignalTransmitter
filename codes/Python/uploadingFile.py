import subprocess

def upload_ino_file(file_path):
    command = ['arduino-cli', 'upload', '-p', 'COM16', '-b', 'arduino:renesas_uno:unor4wifi', file_path]
    print("Running command: " + ' '.join(command))
    result = subprocess.run(command, capture_output=True, text=True)
    if result.stderr:
        print(f'Error: {result.stderr}')
    else:
        print(f'Upload completed with results: {result.stdout}')

# Specify the path to your .ino file
ino_file_path = 'C:\\Users\\rolni\\kody\\Dziekan\\SignalTransmitter\\codes\\ArduinUno\\firstBoss\\firstBoss.ino'

# Call the function with the path
upload_ino_file(ino_file_path)