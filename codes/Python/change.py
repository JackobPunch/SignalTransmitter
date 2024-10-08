def modify_ino_file(file_path, changes):
    # Step 1: Open the .ino file in read mode
    with open(file_path, 'r') as file:
        content = file.read()

    # Step 2: Make the necessary changes to the content
    # For example, let's append the changes to the end of the file
    modified_content = changes + "\n" + content

    # Step 3: Open the .ino file in write mode
    with open(file_path, 'w') as file:
        # Step 4: Write the modified content back to the file
        file.write(modified_content)

    # Step 5: Close the file (handled by 'with' statement)

# Example usage
if __name__ == "__main__":
    file_path = r'C:\Users\rolni\kody\Dziekan\SignalTransmitter\codes\Python\main\main.ino'
    changes = '// Your changes here\nvoid newFunction() {\n  // Function implementation\n}'
    modify_ino_file(file_path, changes)