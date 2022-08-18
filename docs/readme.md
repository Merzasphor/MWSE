# MWSE Documentation

Looking for MWSE documentation? Please [click here](https://mwse.github.io/MWSE/).


## Synopsis

The docs for this project are created for [GitHub Pages](https://pages.github.com/) using [mkdoc](https://www.mkdocs.org). Documentation is done in the Markdown format. Once a doc is pushed to this repository it will automatically be updated at [the documentation site](https://mwse.github.io/MWSE/).


## Autocomplete Definitions

Some portions of the docs, include Lua type information, events, and APIs, are auto-generated using the content in the autocomplete root folder. Edit these definitions instead, and run the configured vscode build task in the autocomplete folder to regenerate the needed files.

There are four basic types of definitions:
- [event definitions](https://github.com/MWSE/MWSE/blob/master/docs/event-definitions-guide.md)
- [type definitions](https://github.com/MWSE/MWSE/blob/master/docs/type-definitions-guide.md)
- [function definitions](https://github.com/MWSE/MWSE/blob/master/docs/function-definitions-guide.md)
- [operator definitions](https://github.com/MWSE/MWSE/blob/master/docs/operator-definitions-guide.md)

Clicking on the links above will take you to a guide for writing mentioned definitions.

## Building

Documentation can also be built locally for testing or personal use. To do this you will need a copy of [Python](https://www.python.org/).

The following modules need to be installed:

```bat
pip install mkdocs mkdocs-material mkdocs-awesome-pages-plugin mkdocs-mermaid2-plugin
```

Another build task is available in vscode to live test the docs locally.

## Developing Tips

When writing the examples, always advise using `tes3.*` constants when available. Also, consider suggesting when a certain function accepts values from `tes3.*` namespace. If writing about color properties, mention the color range, e.g. [0.0, 1.0] or [0, 255]. Note that some older areas of the documentation might not follow the conventions established in the guides above. Those can be updated if editing the affected definitions.

Some parts of the documentation are written by hand. Namely, those in:
- docs\source\references
- docs\source\guides

For a list of all the available features supported by our documentation see Material for MkDocs' [documentation](https://squidfunk.github.io/mkdocs-material/reference/).

### Admonitions

The following admonition classes are available: `abstract`, `attention`, `bug`, `caution`, `check`, `cite`, `danger`, `done`, `error`, `example`, `fail`, `failure`, `faq`, `help`, `hint`, `important`, `info`, `missing`, `note`, `question`, `quote`, `success`, `summary`, `tip`, `tldr`, `todo`, `warning`.

### Key Combinations

To annotate key combinations with style you can use the syntax provided by markdown. A key or combination of key presses is surrounded by `++` with each key press separated with a single `+`. An example: `++ctrl+x++`. For more info see the related extension's [documentation](https://facelessuser.github.io/pymdown-extensions/extensions/keys/).

### Snippets

Snippets is an extension to insert markdown or HTML snippets into another markdown file. Snippets is great for situations where you have content you need to insert into multiple documents. For more info see the related extension's [documentation](https://facelessuser.github.io/pymdown-extensions/extensions/snippets/).

### Fenced Code Blocks

The [SuperFences extension](https://squidfunk.github.io/mkdocs-material/setup/extensions/python-markdown-extensions/#superfences) allows for arbitrary nesting of code and content blocks inside each other, including admonitions, tabs, lists and all other elements.
