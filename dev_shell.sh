#!/bin/sh

git submodule init
nix develop --extra-experimental-features 'nix-command flakes' nix -c $SHELL
