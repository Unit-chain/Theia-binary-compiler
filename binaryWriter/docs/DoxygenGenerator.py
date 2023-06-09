import os
import shutil

def update_doxyfile():
    # Определение операционной системы
    if os.name == "posix":  # Unix-подобные системы (Linux, macOS, BSD)
        output_directory = "docs_unix"
        if shutil.which("dot"):
            dot_path = shutil.which("dot")
        else:
            print("Graphviz (dot) is not found. Install Graphviz with Homebrew (brew install graphviz) or specify the path manually in the script.")
            return
        html_extra_files = ""
        perl_path = shutil.which("perl")
    elif os.name == "nt":  # Windows
        output_directory = "docs_windows"
        dot_path = r"C:\Program Files\Graphviz\bin\dot.exe"
        html_extra_files = "windowspath.css"
        perl_path = r"C:\Program Files\Perl"  # Путь до Perl по умолчанию на Windows
    else:
        print("Unsupported operating system.")
        return

    # Копирование исходного файла Doxyfile
    shutil.copy2("Doxyfile.in", "Doxyfile")

    # Чтение содержимого файла Doxyfile
    with open("Doxyfile", "r") as file:
        doxyfile_content = file.read()

    # Замена путей в Doxyfile
    doxyfile_content = doxyfile_content.replace("OUTPUT_DIRECTORY       = docs", f"OUTPUT_DIRECTORY       = {output_directory}")
    doxyfile_content = doxyfile_content.replace("DOT_PATH               =", f"DOT_PATH               = {dot_path}")
    doxyfile_content = doxyfile_content.replace("HTML_EXTRA_FILES       =", f"HTML_EXTRA_FILES       = {html_extra_files}")
    doxyfile_content = doxyfile_content.replace("PERL_PATH              =", f"PERL_PATH              = {perl_path}")

    # Запись обновленного содержимого в Doxyfile
    with open("Doxyfile", "w") as file:
        file.write(doxyfile_content)

    print("Doxyfile updated successfully.")

# Обновление Doxyfile
update_doxyfile()
