" === BASIC VIM CONFIG FOR COMPETITIVE PROGRAMMING ===

" Enable syntax highlighting
syntax on

" Line numbers
set relativenumber

" Tab settings (4 spaces)
set tabstop=4
set shiftwidth=4
set expandtab        " Use spaces instead of tabs

" Auto indent new lines
set autoindent
set smartindent

" Highlight matching brackets
set showmatch

" Keep things fast and clean
set nowrap           " Don't wrap long lines
set nocompatible     " Use modern Vim features

" Compile and run C++ with <F5>
nmap <F5> :w<CR>:!g++ -Wall -O2 -std=c++23 % -o %< && ./%<<CR>

" Insert template with <F2> (make sure to have cpp_template.cpp ready)
command! InsertTemplate 0r ~/vim-cp-setup/templates/template.cpp
nmap <F2> :InsertTemplate<CR>

