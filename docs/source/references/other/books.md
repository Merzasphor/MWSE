# Game Books

In Morrowind, books are written in simplified HTML. The subset of HTML used by Morrowind is discussed in the next paragraph.


## Tags

Tags are the basic building block of HTML documents. Each tag is enclosed in angle brackets &lt;&gt;. In general, a tag affects a portion of the document inside the opening and closing tag. The closing tag has a slash (`/`) in front. For example, &lt;tag&gt; is an opening tag, while &lt;/tag&gt; is a closing tag.

Some tags allow specifying additional formatting information inside the opening tag. The tags are case insensitive, and most of Morrowind's books have uppercase tags.

The tags are space sensitive.
```HTML
<font color="002200"> This works
<font color = "002200"> This doesn't work
```

The available tags are:
- &lt;div&gt; - text alignment
- &lt;font&gt; - text style
- &lt;br&gt; - a new line
- &lt;img&gt; - inserts an image

### &lt;div align="options"&gt;

The `div` tag is used for aligning text. The `"options"` available are `"center"`, `"left"`, and `"right"`, which align the text correspondingly. The `div` tag is an exception to the rule because it doesn't need to have a closing tag. Instead, this tag will affect the whole book's text after the tag or until another `div` tag occurs.

### &lt;font color="textCol" size="num" face="fontName"&gt;

The `font` tag changes the appearance of the book's text. The first option available in this tag is `"textCol"`. The color is a string of six hexadecimal digits where two correspond to one color channel: "RRGGBB". The default font color is black ("000000"). The size option will change the text's size. The most common font size for Morrowind's books is "3". The size needs to be a natural number. The face option (from typographical typeface) will change the font used to render the book's text. The available `"fontName"`s are "Magic Cards", "Century Gothic", and "Daedric". The default font is "Magic Cards" and doesn't need to be specified. Not all the options need to be specified, but if more than one is specified, they need to be in the above order.

#### Overriding Behavior

If a `font` tag is encountered while one `font` tag already affects the text, another `font` tag will override the settings from the previous tag. For text to render properly, the paragraphs with different font settings need to be set apart with &lt;br&gt; tags at the beginning and end. The results can be unexpected if this rule isn't followed. Here is an example of text with two different font styles:

```HTML
<font color="002200" size="3" face="Magic Cards">
This text is rendered green in Magic Cards font.
</font><br>
<font color="000022" size="3" face="Daedric">
This text is rendered blue in Daedric font.
</font><br>
```

### &lt;br&gt;

The `br` tag inserts a newline character into the book's text. One `br` tag is needed at the end of the book's text to render properly. Otherwise, no content is rendered.

### &lt;img src="imageName.extension" width="pixels" height="pixels"&gt;

The `img` tag inserts an image in the book. For images to be inserted in the text properly, they need to be set apart from the surrounding text with `br` tags. The `src` specifies the name of the image to insert. The image needs to be in one of the texture formats supported by Morrowind. The location of the image needs to be the `Data Files\BookArt` folder. The extension can be `.bmp`, `.tga` or `.dds`. It doesn't matter which one is it, but it needs to be one of the specified for the image to be rendered.

The image dimensions are in pixels, and the image will be stretched if the aspect ratio isn't the same. The maximal height is 327 pixels for books. The width of the image isn't restricted by the engine. After a point part of the image doesn't fit the book. Scrolls don't have restrictions on the image's dimensions, but too big images just won't fit the scroll.


## Additional Notes

The book HTML is extended to allow runtime replacement of [text defines](https://en.uesp.net/wiki/Morrowind_Mod:Text_Defines). The text defines for books can start with `%` or `^` followed by the variable's name. The variables that can be replaced include all global variables, plus some additional ones listed on the linked page.


## Further Reading

 - The Construction Set help
 - An example file called "Morrowind Books HTML.htm" is found in the `Data Files\BookArt\` directory.
 - Text of the existing books in the game can be seen in the Construction Set.