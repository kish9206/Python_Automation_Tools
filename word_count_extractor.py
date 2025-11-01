import os, csv

def get_word_count(file_path):
    with open(file_path, 'r', encoding='utf-8', errors='ignore') as text_file:
        lines = text_file.readlines()
    word_count = sum(len(line.split()) for line in lines)
    return os.path.basename(file_path), word_count

if __name__ == "__main__":
    folder_path = input("Enter folder path: ").strip()
    output_file = "word_summary.csv"

    with open(output_file, 'w', newline='', encoding='utf-8') as csvfile:
        writer = csv.writer(csvfile)
        writer.writerow(["File Name", "Word Count"])

        for file in os.listdir(folder_path):
            if file.endswith(".txt"):
                file_path = os.path.join(folder_path, file)
                name, count = get_word_count(file_path)
                writer.writerow([name, count])
