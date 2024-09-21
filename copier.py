import os
import pyperclip

def copy_files_to_clipboard():
    # List to hold the content
    content_list = []
    
    # Get all .cpp and .h files in the current directory
    for filename in os.listdir('.'):
        if filename.endswith('.cpp') or filename.endswith('.h'):
            # Read the content of the file
            with open(filename, 'r') as file:
                content = file.read()
            
            # Format the content as specified
            formatted_content = f"Content of {filename} file:\n//\n{content}\n//-----------------------------------\n"
            content_list.append(formatted_content)
    
    # Join all the formatted content
    full_content = "\n".join(content_list)
    
    # Copy the full content to the clipboard
    pyperclip.copy(full_content)
    print("Content copied to clipboard.")

if __name__ == "__main__":
    copy_files_to_clipboard()
