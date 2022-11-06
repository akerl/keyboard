#!/usr/bin/env ruby

files = Dir.glob('*/*.ino')

start_regex = /^KEYMAPS\($/
end_regex = %r{^\) \/\/ KEYMAPS\($}
key_regex = %r{ (?:[()\w]+,|\/\*blank\*\/)}

files.each do |file|
  orig_file = File.read(file)
  before, start_str, rest = orig_file.partition(start_regex)
  keymaps, end_str, after = rest.partition(end_regex)
  pad = keymaps.scan(key_regex).map(&:size).max

  keymaps = keymaps.split("\n").map do |line|
    next line unless line =~ key_regex
    ' ' + line.scan(key_regex).map { |x| x.ljust(pad) }.join.rstrip
  end.join("\n")

  new_file = [before, start_str, keymaps, "\n", end_str, after].join
  File.open(file, 'w') { |fh| fh << new_file }
end
