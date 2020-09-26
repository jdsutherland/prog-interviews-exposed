class Employee
  include Comparable

  attr_reader :first_name, :last_name

  def initialize(first_name, last_name)
    @first_name = first_name
    @last_name = last_name
  end

  def <=>(other)
    result = first_name <=> other.first_name
    result.zero? ? last_name <=> other.last_name
                 : result
  end

  def inspect
    "#{first_name} #{last_name}"
  end
end

emp1 = Employee.new('Alice', 'Aliceson')
emp2 = Employee.new('Alice', 'Boberson')

raise 'hell' if [emp2, emp1].sort != [emp1, emp2]
