# frozen_string_literal: true

def first_nonrepeated_char(string)
  seen = Hash.new(0)
  string.each_char do |char|
    seen[char] += 1
  end

  string.each_char do |char|
    return char if seen[char] == 1
  end
  ''
end

p first_nonrepeated_char('total')
p first_nonrepeated_char('teeter')
p first_nonrepeated_char('moom')
