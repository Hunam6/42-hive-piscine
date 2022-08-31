#!/bin/sh

GLOBIGNORE=".:.."

cd $(git rev-parse --show-toplevel)
git check-ignore *
git check-ignore **/*