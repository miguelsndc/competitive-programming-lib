let mapleader = "\<Space>"
" === BASIC VIM CONFIG FOR COMPETITIVE PROGRAMMING ===

" Enable syntax highlighting
syntax on
colorscheme jellybeans

noremap <C-s> <ESC>:w<CR>
noremap <Leader>b ^
noremap <Leader>e <ESC>:e .<CR>
noremap <Leader>r <C-R>
noremap <Leader>j <C-W><C-J>
noremap <Leader>u i_<ESC>r
noremap <Leader>n :vs 
noremap <Leader>q :q<CR>
noremap <Leader>o <C-O>
noremap <Leader>i <C-I>
noremap <Leader>a ggVG
noremap <Leader>/ 0i//<ESC>
noremap <Leader>s :source ~/.vimrc <CR>

" Line numbers
set relativenumber
set t_Co=256
set tabstop=4
set expandtab        " Use spaces instead of tabs
set smartindent
set autoindent
set expandtab
set smarttab
set shiftwidth=4
set tabstop=4
set number
set hlsearch
set ignorecase
set incsearch
set mousehide
set noswapfile
set noerrorbells
set history=1000
set nowrap           " Don't wrap long lines
set nocompatible     " Use modern Vim features
set backspace=indent,eol,start
set clipboard=unnamedplus
" Compile and run C++ with <F5>
nmap <F5> :w<CR>:!g++ -Wall -O2 -std=c++23 % -o %< && ./%<<CR>
nmap <F9> :w<CR>:!g++ -Wall -O2 -std=c++23 -DDEBUG % -o %< && ./%<<CR>

" Insert template with <F2> (make sure to have cpp_template.cpp ready)
command! InsertTemplate 0r ~/vim-cp-setup/templates/template.cpp
nmap <F2> :InsertTemplate<CR>
call plug#begin()
    Plug 'sheerun/vim-polyglot'
    Plug 'SirVer/ultisnips'
    let g:UltiSnipsExpandTrigger = '<tab>'
    let g:UltiSnipsJumpForwardTrigger = '<tab>'
    let g:UltiSnipsJumpBackwardTrigger = '<s-tab>'
    "let g:UltiSnipsJumpForwardTrigger="<c-b>"
    "let g:UltiSnipsJumpBackwardTrigger="<c-z>"
    "let g:UltiSnipsEditSplit="vertical"
    Plug 'honza/vim-snippets'
call plug#end()
