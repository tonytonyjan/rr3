# Rr3

## Installation

```
$ gem install rr3
```

## Usage

```ruby
t = Rr3::Tree.new(10)
t.insert_path "/foo/bar"
t.compile!
t.match("/foo/bar")   # => true
t.match("/foo/barr")) # => false
t.dump(0)
```