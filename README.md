
Sometimes `#!/usr/bin/env` isn't sufficient. What if you wanted this:

    #!/usr/bin/env jruby --1.9
    puts RUBY_VERSION

You'd get:

    /usr/bin/env: jruby --1.9: No such file or directory

That sucks. Use shebang instead.

    #!/usr/bin/shebang jruby --1.9
    puts "Hello from #{RUBY_VERSION}"

Working output:

    Hello from 1.9.2

