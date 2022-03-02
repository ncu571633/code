set backspace=eol,indent,start
set autoindent

" don't highlight the last search upon startup
set viminfo="h"

" set font size
if has("gui_running")
  if has("gui_gtk2")
    set guifont=Inconsolata\ 12
  elseif has("gui_macvim")
    set guifont=Menlo\ Regular:h14
  elseif has("gui_win32")
    set guifont=Consolas:h11:cANSI
  endif
endif

" max vim window
set lines=999 columns=999

" Do C-style auto indentation on C/C++/Perl files only :)
:filetype on
:autocmd FileType c,cpp,perl :set cindent

" stop Vim from beeping all the time
set vb

set tabstop=4
set shiftwidth=4
set softtabstop=4
" uncomment to insert spaces instead of a tab when tab is pressed
set expandtab
set smarttab
set nu
set mouse=a

set sm "show matching brace or parentheses while inserting 
"auto match {}
"inoremap ( ()<LEFT>
"inoremap { {}<LEFT>
"inoremap [ []<LEFT>

set ruler

syntax on
set background=dark
if has('gui_running')
    colorscheme torte
endif
" uncomment to use a different color map
":hi Comment   term=bold cterm=NONE ctermfg=Blue ctermbg=NONE gui=NONE guifg=Blue guibg=NONE
":hi Constant  term=underline cterm=NONE ctermfg=Red ctermbg=NONE gui=NONE guifg=Magenta guibg=NONE
":hi Special   term=bold cterm=NONE ctermfg=Magenta ctermbg=NONE gui=NONE guifg=SlateBlue guibg=NONE
":hi Identifier   term=underline cterm=NONE ctermfg=Cyan ctermbg=NONE gui=NONE guifg=Cyan guibg=NONE
":hi Statement term=bold cterm=NONE ctermfg=Yellow ctermbg=NONE gui=bold guifg=Brown guibg=NONE
":hi PreProc   term=underline cterm=NONE ctermfg=Magenta ctermbg=NONE gui=NONE guifg=Purple guibg=NONE
":hi Type      term=underline cterm=NONE ctermfg=Green ctermbg=NONE gui=bold guifg=SeaGreen guibg=NONE
":hi Underlined   term=underline cterm=underline ctermfg=Magenta gui=underline guifg=SlateBlue
":hi Ignore term=NONE cterm=NONE ctermfg=white ctermbg=NONE gui=NONE guifg=bg guibg=NONE

"Tell you if you are in insert mode
set showmode

"match parenthesis, i.e. ) with (  and } with {
set showmatch

"ignore case when doing searches
set ignorecase

"tell you how many lines have been changed
set report=0
