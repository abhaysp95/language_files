#!/usr/bin/env python

from rich import print
from rich.console import Console

print("hello, [bold magenta]World[/bold magenta]!", ":vampire:", locals())

console = Console()
console.print("Hello", "World!", style="cyan")
console.print("Where there is a [bold yellow]Will[/bold yellow], there [u]is[/u] a [i]way[/i].")
