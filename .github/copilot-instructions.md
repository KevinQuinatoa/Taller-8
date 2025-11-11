# Copilot / AI agent instructions — quick guide

Purpose: Help an AI coding agent be productive in this tiny C project.

1) Repo snapshot
- Single-source C program: `main.c` (procedural, menu-driven, Spanish UI strings).
- No build scripts, tests, or CI files present.

2) What to expect when editing
- Keep Spanish identifiers and printed UI text consistent (e.g., `nombreP`, `recursos`, `tiempoC`) — the codebase currently uses Spanish for prompts and variable names.
- Current `main.c` is an incomplete menu program. Notable, discoverable issue: `int nombreP[5][50]` is present but looks like it should be `char nombreP[5][50]` if it is meant to hold strings (names). Flag and fix that when implementing features.

3) Build & run (Windows / PowerShell)
- Preferred quick build with GCC (MinGW/MSYS or WSL):

```powershell
gcc -std=c11 -Wall -Wextra -O0 -g -o main.exe main.c
.\main.exe
```

- MSVC (Developer Command Prompt) alternative:

```powershell
cl /W4 /Zi main.c
.\main.exe
```

If you add more source files, update the command to list them or create a simple `build.ps1` task file.

4) Coding patterns and project conventions
- Small procedural C program: prefer small helper functions in the same file for now. If you split code across files, create a `.h` header with include guards and keep implementation in `.c` files.
- Keep prints and user-facing text in Spanish to match the current style.
- Use `-Wall -Wextra` locally to catch common issues (signed/unsigned, implicit conversions).

5) Common edits an AI might be asked to do (examples)
- Fix the name-storage bug: change `int nombreP[5][50]` to `char nombreP[5][50]` and update code that reads/prints names (use `fgets`/`scanf_s` with bounds).
- Flesh out the menu: implement subfunctions (e.g., `void mostrar_menu(void)`) and keep `main` as a thin dispatcher.

6) Debugging tips
- Build with `-g` and run under `gdb` or use the VS Code C/C++ extension with a simple launch configuration. On Windows you can also use the MSVC debugger if compiling with `cl`.

7) Pull request / edit guidance
- Make small, focused changes. Add short comments in Spanish where the UI text is changed so maintainers understand intent.

If anything in this file is unclear or you'd like more detail (task-specific examples, a `build.ps1`, or a minimal `tasks.json` for VS Code), tell me what to add and I'll iterate.
