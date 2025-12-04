# generate_mazes.py
from maze_dataset import MazeDataset, MazeDatasetConfig
from maze_dataset.generation import LatticeMazeGenerators
import os

# 1. Path to your mazes folder
output_folder = r"C:\Users\raziu\Project\mazes"

# Ensure folder exists
os.makedirs(output_folder, exist_ok=True)

# 2. Configure the dataset
cfg = MazeDatasetConfig(
    name="my_mazes",
    grid_n=50,         # 50x50 maze
    n_mazes=100,       # number of mazes to generate
    maze_ctor=LatticeMazeGenerators.gen_dfs,  # maze generation algorithm
    maze_ctor_kwargs=dict(do_forks=False)    # adjust complexity
)

# 3. Generate dataset
dataset = MazeDataset.from_config(cfg)

# 4. Save mazes to your folder
for i, m in enumerate(dataset.mazes):
    ascii_maze = m.as_ascii()
    file_path = os.path.join(output_folder, f"maze_{i}.txt")
    with open(file_path, "w") as f:
        f.write(ascii_maze)

print(f"Generated {len(dataset.mazes)} mazes in: {output_folder}")

