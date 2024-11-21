using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LinqTasksConsoleApp
{
    class TaskItem
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public bool IsCompleted { get; set; }

        public TaskItem(int id, string name, bool isCompleted)
        {
            Id = id;
            Name = name;
            IsCompleted = isCompleted;
        }

        public override string ToString()
        {
            return $"Id: {Id}, Name: {Name}, IsCompleted: {IsCompleted}";
        }
    }
}
