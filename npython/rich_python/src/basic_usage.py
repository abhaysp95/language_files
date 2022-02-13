import os
import sys
import time
import requests
from rich import print
from rich.console import Console
from rich.text import Text
from rich.theme import Theme
from rich.traceback import install
from rich.table import Table
from rich.progress import track
from rich.progress import BarColumn, Progress, TimeRemainingColumn
from rich import box
from rich.columns import Columns
from rich.panel import Panel

# print
print(f"Some math: 2 + 2 = {2 + 2}")
print({"a": [1, 2, 3], "b": [4, 5, 6]})

# console
console = Console()
console.print("some text")
console.print("some text", style="bold")
console.print("some text", style="bold underline")
console.print("some text", style="bold underline green")
console.print("some text", style="bold underline red on white")

console.print("[bold]This is [cyan]some[/] text[/].")

# text
text = Text("Hello, World")
text.stylize("bold magenta", 0, 6)
console.print(text)

# theme
custom_theme = Theme({"success": "green", "error": "red"})

console = Console(theme=custom_theme)
console.print("Operation successful", style="success")
console.print("Operation failed", style="error")
console.print("Operation [error]failed[/]")

# emojis
console.print(":thumbs_up: File downloaded")
console.print(":apple: :smile:")

# log
for x in range(10):
    console.log(f"printing {x}")
    time.sleep(0.2)

# traceback
install() # overrides default python traceback to rich.traceback

def add(x: int, y: int) -> int:
    console.log("Adding two numbers", log_locals=True)
    return x + y

add(1, 2)
add(1.1, 2.2)
# add(1, "a")

# save HTML
console = Console(record=True)

try:
    add(1, 2)
    add(1.1, 2.2)
    add(1, "a")
except:
    console.print_exception()

console.save_html("traceback.html")

# table
table = Table(title="Star Wars Movies")  # new table object(with table title), default arg is a column title

table.add_column("Released", style="cyan")
table.add_column("Title", style="magenta")
table.add_column("Box Office", style="green", justify="right")

table.add_row("Dec 20, 2019", "Star Wars: The Rise of SkyWalker", "$952,110,690")
table.add_row("May 25, 2018", "Solo: A Star Wars Story", "$393,151,347")
table.add_row("Dec 15, 2017", "Star Wars Ep. V111: The Last Jedi", "$1,332,539,889")
table.add_row("Dec 16, 2016", "Rogue One: A Star Wars Story", "$1,332,449,889")

console = Console()
console.print(table)

# progressbar
for x in track(range(10), description="Processing..."):
    print(f"Working {x}\r")
    time.sleep(0.5)

# some progressbar examples
DOWNLOAD_DIR="/home/raytracer/"


files = [
    'https://media3.giphy.com/media/ZZxdru3NM5L2AULyil/giphy.gif',
    'https://media2.giphy.com/media/fdG206uGu4MhbQCoYt/giphy.webp',
    'https://media0.giphy.com/media/VCnarjHdw5Sqelr9pe/source.mp4'
]

def download_file(file):
    res = requests.get(file)
    file_name = file.split("/")[-1]

    with open(f"{DOWNLOAD_DIR}/{file_name}", "wb") as f:
        f.write(res.content)

for file in track(files, "Downloading files..."):
    download_file(file)

progress = Progress(
        '[progress.description]{task.description}',
        BarColumn(),
        '[magenta]{task.completed} of {task.total} files downloaded',
        TimeRemainingColumn()
        )

with progress:
    task = progress.add_task("Downloading files...", total=len(files))

    for file in files:
        download_file(file)
        progress.update(task, advance=1)


# columns and panel
def file_info(file):
    file_name, ext = os.path.splitext(file)
    file_type = 'directory' if os.path.isdir(file) else 'file'

    return f"[bold]NAME[/bold]: {file_name}\n[bold]TYPE[/bold]: {file_type}\n[bold]EXT[/bold]: {ext if file_type == 'file' else '-'}"

console = Console()
files = [Panel(file_info(file), box=box.DOUBLE_EDGE) for file in os.listdir(sys.argv[1])]
console.print(Columns(files))
