class Person
  attr_accessor :name, :friends, :visited

  def initialize(name)
    @name = name
    @friends = []
  end

  def add_friend(friend)
    @friends << friend
  end

  def display_network
    to_reset = [self]
    queue = [self]
    self.visited = true

    while queue.any?
      current_vertex = queue.shift
      puts current_vertex.name

      current_vertex.friends.each do |friend|
        puts "friend: #{friend.name}"
        if !friend.visited
          friend.visited = true
          queue << friend
          to_reset << friend
        end
      end
    end

    to_reset.each do |node|
      node.visited = false
    end
  end
end

alice = Person.new("Alice")
bob = Person.new("Bob")
candy = Person.new("Candy")
derek = Person.new("Derek")
elaine = Person.new("Elaine")
fred = Person.new("Fred")
gina = Person.new("Gina")
helen = Person.new("Helen")
irena = Person.new("Irena")

alice.add_friend(bob)
alice.add_friend(candy)
alice.add_friend(derek)
alice.add_friend(elaine)
bob.add_friend(fred)
fred.add_friend(helen)
derek.add_friend(gina)
gina.add_friend(irena)

bob.add_friend(alice)
candy.add_friend(alice)
derek.add_friend(alice)
elaine.add_friend(alice)

fred.add_friend(bob)
helen.add_friend(fred)
gina.add_friend(derek)
irena.add_friend(gina)

alice.display_network
