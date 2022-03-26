from console import my_console

my_console.print([1, 2, 3])
my_console.print("[blue underline]looks like a link")
my_console.print(locals())
my_console.print("FOO", style="white on blue")

my_console.log("Hello, world!!!")

my_console.print_json('[false, true, null, "Foo"]')

from rich.json import JSON
my_console.log(JSON('["Foo", "Bar"]'))


# low level output
my_console.out("Locals", locals())

# draw horizontal line with optional title
my_console.rule("[bold red]Chapter 2")

def fact(num):
    if num <= 1:
        return 1
    return num * fact(num - 1)

# with my_console.status("working...", spinner="dots"):
    # while True:
        # print("somethin")

my_console.width = 20

style = "bold white on blue"
my_console.print("Rich", style=style)
my_console.print("Rich", style=style, justify="left")
my_console.print("Rich", style=style, justify="center")
my_console.print("Rich", style=style, justify="right")

from typing import List
from rich.console import OverflowMethod

supercali = "supercalifragilisticexpialidocious"

overflow_methods: List[OverflowMethod] = ["fold", "crop", "ellipsis"]  # there's also "ignore"

for overflow in overflow_methods:
    my_console.rule(overflow)
    my_console.print(supercali, overflow=overflow, style="bold green")
    my_console.print()
