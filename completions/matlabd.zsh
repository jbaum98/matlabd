if [[ ! -o interactive ]]; then
    return
fi

compctl -K _matlabd matlabd

_matlabd() {
  local word words completions
  read -cA words
  word="${words[2]}"

  if [ "${#words}" -eq 2 ]; then
    completions="$(matlabd commands)"
  else
    completions="$(matlabd completions "${word}")"
  fi

  reply=("${(ps:\n:)completions}")
}
