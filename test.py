import re
BLOCK_TAG_START = '{%'
BLOCK_TAG_END = '%}'
VARIABLE_TAG_START = '{{'
VARIABLE_TAG_END = '}}'
COMMENT_TAG_START = '{#'
COMMENT_TAG_END = '#}'
TRANSLATOR_COMMENT_MARK = 'Translators'
SINGLE_BRACE_START = '{'
SINGLE_BRACE_END = '}'
tag_re = (re.compile('(%s.*?%s|%s.*?%s|%s.*?%s)' %
          (re.escape(BLOCK_TAG_START), re.escape(BLOCK_TAG_END),
           re.escape(VARIABLE_TAG_START), re.escape(VARIABLE_TAG_END),
           re.escape(COMMENT_TAG_START), re.escape(COMMENT_TAG_END))))
data="sdlkajdf{{variable}}sdfklasjf{%block%}{#comment#}dslkfjasldfk"
a=tag_re.split(data)
print a
