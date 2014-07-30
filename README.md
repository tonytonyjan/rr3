# Rr3

## Dependency

### OS X

    brew install r3

### Ubuntu PPA

The PPA for libr3 can be found in https://launchpad.net/~r3-team/+archive/libr3-daily

## Installation

    $ gem install rr3

## Usage

```ruby
  @tree = Rr3::Tree.new(10)
  @tree.insert_path "/bar"
  @tree.insert_path "/zoo", 9527
  @tree.insert_path "/foo/bar", 9527
  @tree.insert_path "/post/{id}", 9527
  @tree.insert_path "/user/{id:\\d+}", 9527
  @tree.compile!
  @tree.match "/user/xxx)  # => false # not matched
  @tree.match "/asd"       # => false
  @tree.match "/bar"       # => nil   # matched, and the route data is `nil`
  @tree.match "/zoo"       # => 9527  # matched, and the route data is `9527`
  @tree.match "/foo/bar)   # => 9527
  @tree.match "/post/1234) # => 9527
  @tree.match "/user/1234) # => 9527
```