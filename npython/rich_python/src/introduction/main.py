import rich
from rich import print
from rich.panel import Panel
from rich import inspect
from rich.color import Color

print("[italic red]hello[/italic red] world", locals())
print(Panel.fit("[bold yellow]Hi, I'm panel", border_style="Red"))
color = Color.parse("red")
inspect(color, methods=True)
dct = {1: "some", 2: "thing"}
inspect(dct, help=True)
inspect(print, methods=True, all=True)
