#!/usr/bin/env ruby

firmware = 'keyboard.ino'
start_regex = /^KEYMAPS\($/
end_regex = %r{^\) \/\/ KEYMAPS\($}
key_regex = %r{ (?:[(\w]+,|\/\*blank\*\/)}

orig_file = File.read(firmware)
before, start_str, rest = orig_file.partition(start_regex)
keymaps, end_str, after = rest.partition(end_regex)
pad = keymaps.scan(key_regex).map(&:size).max

keymaps = keymaps.split("\n").map do |line|
  next line unless line =~ key_regex
  ' ' + line.scan(key_regex).map { |x| x.ljust(pad) }.join.rstrip
end.join("\n")

new_file = [before, start_str, keymaps, "\n", end_str, after].join
File.open(firmware, 'w') { |fh| fh << new_file }
