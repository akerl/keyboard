#!/usr/bin/env ruby

firmware = 'Model01-Firmware.ino'
start_regex = /^KEYMAPS\($/
end_regex = /^\) \/\/ KEYMAPS$/
key_regex = / (\w+,|/\*blank\*/)/

orig_file = File.read(firmware)
before, start_str, rest = orig_file.partition(start_regex)
keymaps, end_str, after = rest.partition(end_regex)

pad = keymaps.scan(key_regex).map(&:size).max - 2

require 'pry'
keymaps = keymaps.split("\n").each do |line|
  next line unless line =~ /,/
  binding.pry
  raise
end.join("\n")

new_file = [
  before,
  start_str,
  keymaps,
  end_str,
  after
].join

File.open(firmware, 'w') { |fh| fh << new_file }

